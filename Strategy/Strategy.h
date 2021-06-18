#pragma once
#include <iostream>

class Strategy // interface
{
public :
	virtual int execute(int a, int b) = 0;
	
};
