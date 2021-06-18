#pragma once
#include"Header.h"
#include"Developer.h"
class Developer
{
public:
	Developer()
	{
#ifdef DEBUG
		cout << "\tConstDev >> " << this << "\n";
#endif // DEBUG
	}

	~Developer()
	{
#ifdef DEBUG
		cout << "\tDestDev >> " << this << "\n";
#endif // DEBUG
	}

	virtual void writeCode() = 0;
};

