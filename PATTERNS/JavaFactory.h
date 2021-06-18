#pragma once
#include"Header.h"
#include"Developer.h"
class JavFactory : public DevFactory
{
public:
	JavFactory()
	{
	}

	~JavFactory()
	{
	}
	Developer* createDeveloper()override
	{
		return new JavaDev();
	}
private:

};
