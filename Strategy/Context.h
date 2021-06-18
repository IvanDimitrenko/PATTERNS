#pragma once

#include <iostream>
#include"Strategy.h"


class Context
{
	Strategy* str;
public:

	Context(Strategy*str = nullptr) :str(str) {}
	void set_strategy(Strategy* str) {
		delete this->str;
		this->str = str;
	}

	int execute_strategy(int a, int b) { return this->str->execute(a, b); }
};








