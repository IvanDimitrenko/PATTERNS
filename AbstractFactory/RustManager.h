#pragma once

#include"ProjectManager.h"
#include<iostream>
class RustManager : public ProjectManager
{
public:

	void managerProject()
	{
		std::cout << "Rust manager maneges rust code" << std::endl;
	}
};