#pragma once
#include"Developer.h"
#include<iostream>

class JavaDeveloper : public Developer
{
public:

	void writeCode()override
	{
		std::cout << "Java developer, write code" << std::endl;
	}
};


