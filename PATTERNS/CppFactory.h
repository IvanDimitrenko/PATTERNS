#pragma once
#include"Header.h"
#include"DevFactory.h"
#include"CppDev.h"

class CppFactory: public DevFactory
{
public:
	CppFactory()
	{
	}

	~CppFactory()
	{
	}
	Developer* createDeveloper()override
	{
		return new CppDev();
	}
private:

};
