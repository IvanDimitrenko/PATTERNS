#pragma once 
#include"ProjectTeamFactory.h"
#include"JavaDev.h"
#include"JavaTester.h"
#include"JavaManager.h"

#include<iostream>

class JavaTeamFactory : public ProjectTeamFactory
{

public:

	Developer* getDeveloper()override
	{
		return new JavaDeveloper();
	}

	Tester* getTester()override
	{
		return new JavaTester();
	}

	ProjectManager* getProjectManager()override
	{
		return new JavaManager();
	}



};

