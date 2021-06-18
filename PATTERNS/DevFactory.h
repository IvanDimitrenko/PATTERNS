#pragma once
#include"Header.h"
#include"Developer.h"
class DevFactory
{
public:


	virtual Developer* createDeveloper() = 0;


};


