#pragma once
#include "Creational/Singleton.h"
#include "Creational/FactoryMethod.h"
#include "Creational/AbstractFactory.h"
#include "Creational/Builder.h"
#include "Creational/Prototype.h"

using namespace Creational;

void DemoSingleton()
{
	std::cout << "Design Patterns - Creational: Singleton demo\n";
	Singleton& singleton = Singleton::Instance();
	singleton.DoSomething();
	std::cout << "--------------------------------------------\n";
}

void DemoFactoryMethod()
{
	std::cout << "Design Patterns - Creational: Factory Method demo\n";
	ConcreteCreatorA creatorA;
	ConcreteCreatorB creatorB;
	ConcreteCreatorC creatorC;
	std::unique_ptr<Product> myProducts[] =
	{
		creatorA.FactoryMethod(),
		creatorB.FactoryMethod(),
		creatorC.FactoryMethod()
	};
	for (const auto& product : myProducts)
	{
		product->Use();
	}
	std::cout << "--------------------------------------------\n";
}

void DemoAbstractFactory()
{
	std::cout << "Design Patterns - Creational: Abstract Factory demo\n";
	ConcreteFactory1 factory1;
	auto x1 = factory1.CreateProductX();
	auto y1 = factory1.CreateProductY();
	x1->Use();
	y1->InteractWith(*x1);

	ConcreteFactory2 factory2;
	auto x2 = factory2.CreateProductX();
	auto y2 = factory2.CreateProductY();
	x2->Use();
	y2->InteractWith(*x2);
	std::cout << "--------------------------------------------\n";
}

void DemoBuilder()
{
	std::cout << "Design Patterns - Creational: Builder demo\n";
	Sandwich lunchSub = Sandwich::Create()
		.SetBread("Wheat")
		.AddMeat("Turkey")
		.AddVeggie("Lettuce")
		.Build();

	lunchSub.Describe();

	Sandwich customSub = Sandwich::Create()
		.SetBread("Italian Herb & Cheese")
		.AddMeat("Roast Beef")
		.AddVeggie("Pickles")
		.AddVeggie("Onions")
		.SetToasted(true)
		.Build();

	customSub.Describe();
	std::cout << "--------------------------------------------\n";
}

void DemoPrototype()
{
	std::cout << "Design Patterns - Creational: Prototype demo\n";
	GameCharacter character("Jamie", 5);
	character.Describe();
	character.FillArray();
	character.Describe();
	std::unique_ptr<Prototype> characterClone1 = character.Clone();
	characterClone1->Describe();
	character.SetName("Jack");
	character.UpdateArray(0, 99);
	character.UpdateArray(1, 100);
	character.UpdateArray(2, 101);
	character.UpdateArray(3, 102);
	character.Describe();
	characterClone1->Describe();
	std::unique_ptr<Prototype> characterClone2 = character.Clone();
	characterClone2->Describe();
	std::cout << "--------------------------------------------\n";
}

void DemoCreationalPatterns()
{
	DemoSingleton();
	DemoFactoryMethod();
	DemoAbstractFactory();
	DemoBuilder();
	DemoPrototype();
}
