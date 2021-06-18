#pragma once
#include"Header.h"
#include"Developer.h"
class JavaDev : public Developer
{

	JavaDev()
	{
#ifdef DEBUG
		cout << "\tConstJav >> " << this << "\n";
#endif // DEBUG
	}

	~JavaDev()
	{
#ifdef DEBUG
		cout << "\tDestJav >> " << this << "\n";
#endif // DEBUG
	}

	void writeCode()override 
	{
		cout << "JavaDev write code >> " << this << "\n";
	}

};


