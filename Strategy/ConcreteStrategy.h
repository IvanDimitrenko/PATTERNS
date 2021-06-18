#pragma once
#include"Strategy.h"

class StrategyAdd :public  Strategy
{
public:
	int execute(int a, int b) override { return a + b; }
};

class StrategySub :public  Strategy
{
public:
	int execute(int a, int b) override { return a - b; }
};

class StrategyMult :public  Strategy
{
public:
	int execute(int a, int b) override { return a * b; }
};

class StrategyDiv :public  Strategy
{
public:
	int execute(int a, int b) override { return a / b; }
};

