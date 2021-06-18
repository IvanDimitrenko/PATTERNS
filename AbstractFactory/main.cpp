#include"Developer.h"
#include"JavaDev.h"
#include"JavaManager.h"
#include"JavaTeamFactory.h"
#include"JavaTester.h"
#include"ProjectManager.h"
#include"ProjectTeamFactory.h"
#include"Tester.h"


#include"RustDev.h"
#include"RustManager.h"
#include"RustTeamFactory.h"
#include"RustTester.h"

#include <iostream>

int main()
{
	ProjectTeamFactory* Javafact = new JavaTeamFactory();

	Developer* javaDev = Javafact->getDeveloper();
	Tester* javaTest = Javafact->getTester();
	ProjectManager* javaMeng = Javafact->getProjectManager();

	javaDev->writeCode();
	javaTest->testCode();
	javaMeng->managerProject();


	std::cout << "\n----------------------------\n\n";


	ProjectTeamFactory* rustfact = new RustTeamFactory();

	Developer* rustDev = rustfact->getDeveloper();
	Tester* rustTest = rustfact->getTester();
	ProjectManager* rustMang = rustfact->getProjectManager();

	rustDev->writeCode();
	rustTest->testCode();
	rustMang->managerProject();

	return 0;
}
