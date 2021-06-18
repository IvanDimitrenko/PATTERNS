#pragma once

#include"Tester.h"
#include<iostream>
class RustTester : public Tester
{
public:

	void testCode()override
	{
		std::cout << "Rust tester, test rust code" << std::endl;
	}

};
