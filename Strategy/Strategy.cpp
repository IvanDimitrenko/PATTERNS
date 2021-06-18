
#include <iostream>
#include"ConcreteStrategy.h"
#include"Context.h"



int main()
{
	Context* culc = new Context(new StrategyAdd);

	std::cout << culc->execute_strategy(1, 1) << std::endl;

	culc->set_strategy(new StrategySub);

	std::cout << culc->execute_strategy(5, 2) << std::endl;

	culc->set_strategy(new StrategyDiv);

	std::cout << culc->execute_strategy(6, 2) << std::endl;


	return 0;
}
