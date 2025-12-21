#pragma once
#include "Behavioral/ChainOfResponsibility.h"

using namespace Behavioral;

void DemoChainOfResponsibility()
{
	std::cout << "Design Patterns - Behavioral: Chain of Responsibility demo\n";
	
	NotEmpty notEmpty;
	MinLength minLen(5);
	NoSpaces noSpaces;

	ValidatorChain chain;
	chain.add(&notEmpty);
	chain.add(&minLen);
	chain.add(&noSpaces);

	if(chain.validate("TestStr"))
	{
		std::cout << "Validation Success\n";
	}

	std::cout << "--------------------------------------------\n";
}

void DemoBehavioralPatterns()
{
	DemoChainOfResponsibility();
}