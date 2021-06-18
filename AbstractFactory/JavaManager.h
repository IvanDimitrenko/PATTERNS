#pragma once

#include"ProjectManager.h"
#include<iostream>
class JavaManager : public ProjectManager
{
public:

	void managerProject()
	{
		std::cout << "Java manager, maneges java code" << std::endl;
	}
};