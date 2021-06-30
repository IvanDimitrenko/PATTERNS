
#include <iostream>


class DifficultClass_A
{
public:
	int i = 10;
	void DO_SMT_A()
	{
		std::cout << "Class A doing your job" << std::endl;
	}
	~DifficultClass_A()
	{
		std::cout << "A_D >> " << this << std::endl;
	}

};

class DifficultClass_B
{
public:
	int j = 20;
	void DO_SMT_B()
	{
		std::cout << "Class B doing your job" << std::endl;
	}
	~DifficultClass_B()
	{
		std::cout << "B_D >> " << this << std::endl;
	}

};
class DifficultClass_C
{
public:
	int h = 5;
	void DO_SMT_C()
	{
		std::cout << "Class C doing your job" << std::endl;
	}
	~DifficultClass_C()
	{
		std::cout << "C_D >> " << this << std::endl;
	}

};

class Facade
{
public:
	Facade()
	{
		A = nullptr;
		B = nullptr;
		C = nullptr;
	}
	Facade(DifficultClass_A* A,DifficultClass_B* B, DifficultClass_C* C)
	{
		this->A = A;
		this->B = B;
		this->C = C;
	}
	Facade(DifficultClass_A&& A, DifficultClass_B&& B, DifficultClass_C&& C) :Facade()
	{
		this->A->i = A.i;
		this->B->j = B.j;
		this->C->h = C.h;

		std::cout <<"A >> " << &A << "\nB >> " << &B << "\nC >> " << &C << std::endl;
	}

	~Facade()
	{
		std::cout << "F_D >> " << this << std::endl;
		delete A;
		delete B;
		delete C;
	}
	 
	void Call_ABC_Work()
	{
		A->DO_SMT_A();
		B->DO_SMT_B();
		C->DO_SMT_C();
	}


private:
	DifficultClass_A* A;
	DifficultClass_B* B;
	DifficultClass_C* C;

};



int main()
{
	{
		Facade* facade = new Facade(DifficultClass_A(), DifficultClass_B(), DifficultClass_C());
		facade->Call_ABC_Work();
		delete facade;
	}

	return 0;
}

