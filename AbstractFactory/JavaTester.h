#pragma once
#include"Tester.h"
#include<iostream>
class JavaTester : public Tester
{
public:

	void testCode()override
	{
		std::cout << "Java tester, test java code" << std::endl;
	}
	
};
