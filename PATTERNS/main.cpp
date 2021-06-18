

#include"Header.h"
#include"JavaDev.h"

#include"Developer.h"
#include"CppFactory.h"
#include"DevFactory.h"
#include"JavaFactory.h"


int main(int arvc, char* arvg[])
{
   
	DevFactory* FactoryCpp = new CppFactory();
	DevFactory* FactoryJava = new JavFactory();
	Developer* Cpp = FactoryCpp->createDeveloper();
	Developer* Java = FactoryJava->createDeveloper();
	
	Cpp->writeCode();
	Java->writeCode();


	return 0;
}
