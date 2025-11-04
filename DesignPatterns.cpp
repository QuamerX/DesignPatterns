#include <iostream>
#include "Creational/Singleton.h"
#include "Creational/FactoryMethod.h"
#include "Creational/AbstractFactory.h"

using namespace Creational;

void DemoSingleton()
{
    std::cout << "Design Patterns - Creational: Singleton demo\n";
    Singleton& singleton = Singleton::Instance();
    singleton.DoSomething();
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
}

int main()
{
    DemoSingleton();
    DemoFactoryMethod();
    DemoAbstractFactory();
    return 0;
}
