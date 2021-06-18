#pragma once
#include"Developer.h"
#include<iostream>

class RustDeveloper : public Developer
{
public:

	void writeCode()override
	{
		std::cout << "Rust developer, write code" << std::endl;
	}
};


