#pragma once

#include"ProjectTeamFactory.h"
#include"RustDev.h"
#include"RustTester.h"
#include"RustManager.h"

#include<iostream>

class RustTeamFactory : public ProjectTeamFactory
{

public:

	Developer* getDeveloper()override
	{
		return new RustDeveloper();
	}

	Tester* getTester()override
	{
		return new RustTester();
	}

	ProjectManager* getProjectManager()override
	{
		return new RustManager();
	}



};