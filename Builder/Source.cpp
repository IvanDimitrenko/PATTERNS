#include <iostream>
#include <boost/lexical_cast/lexical_cast_old.hpp>
#include <boost/any.hpp>
#include<list>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::endl;
/*
Builder is a creational design pattern that lets you construct complex objects step by step. 
The pattern allows you to produce different types and representations of an object using the same construction code.
*/




class Part;
class Product
{
public:
	//std::vector<boost::any>* list_element = new std::vector<boost::any>();
	std::vector<Part*>* list_element = new std::vector<Part*>();

	
};

class Product1 : public Product
{

	
};


class Part 
{
private:
	string Name;
public:
	Part() {};
	Part(string name) : Name(name) {};
};

class PartA : public Part
{
public:
	PartA(string name) :Part(name) {};
	PartA() {};
};

class PartB : public Part
{
public:
	PartB(string name) :Part(name) {};
	PartB() {};
};

class PartC : public Part
{
public:
	public:PartC(string name) :Part(name) {};
	PartC() {};
};

class  Builder
{
public:
	virtual ~Builder() {}
	virtual void ProducePartA() const = 0;
	virtual void ProducePartB() const = 0;
	virtual void ProducePartC() const = 0;
private:

};

class ConcreteBuilder1 : public Builder
{
private:
	Product1* product ;
public:

	 ConcreteBuilder1()
	 {
		product = new Product1();
	 }
	 void ProducePartA()const override
	 {
		product->list_element->push_back(new PartA("partA"));
	 }
	 void  ProducePartB()const override
	 {
 		 product->list_element->push_back(new PartB("partB"));
	 }
	 void  ProducePartC()const override
	 {
		 product->list_element->push_back(new PartC("partC"));
	 }
	 Product1* get_product()
	 {
		 return product;
	 }
};

class Director
{
public:


	void set_builder(Builder* builder)
	{
		this->builder = builder;
	}

	void builde_ABC()
	{
		builder->ProducePartA();
		builder->ProducePartB();
		builder->ProducePartC();
	}
	void builde_CBA()
	{
		builder->ProducePartC();
		builder->ProducePartB();
		builder->ProducePartA();
	}
	void builde_ACB()
	{
		builder->ProducePartA();
		builder->ProducePartC();
		builder->ProducePartB();
	}
	
private:
	Builder* builder;
};




// Test

class Base
{
public:
	int g = 0;

};
class Derived_A :public Base
{
public:
	int t = 0;
};
class Derived_B :public Base
{
public:
	int i = 0;
};
class Derived_C :public Base
{
public: 
	int j = 0;
};

int main(int argc, char **argv)
{
	
	ConcreteBuilder1* bul = new ConcreteBuilder1();

	Director* dir = new Director();
	dir->set_builder(bul);
	dir->builde_ABC();
	Product* product = bul->get_product();

	for (size_t i = 0; i < product->list_element->size(); i++)
	{
		product->list_element[i];
	}


	return 0;
}


