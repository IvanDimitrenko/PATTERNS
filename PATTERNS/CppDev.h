#include"Header.h"
#include"Developer.h"
class CppDev : public Developer
{
public:

	CppDev()
	{
#ifdef DEBUG
		cout << "\tConstCpp >> " << this << "\n";
#endif // DEBUG
	}

	~CppDev()
	{
#ifdef DEBUG
		cout << "\tDestCpp >> " << this << "\n";
#endif // DEBUG
	}


	void writeCode ()override
	{
		 cout << "CppDev write code >> " << this << "\n";
	}

};
