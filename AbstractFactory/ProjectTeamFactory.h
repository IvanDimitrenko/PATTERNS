#pragma once

#include"Developer.h"
#include"ProjectManager.h"
#include"Tester.h"

class ProjectTeamFactory
{
public:

	virtual Tester* getTester() = 0;

	virtual Developer* getDeveloper() = 0;

	virtual ProjectManager* getProjectManager() = 0;


};