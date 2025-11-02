#include <iostream>
#include "Creational/Singleton.h"
#include "Creational/FactoryMethod.h"

using namespace Creational;

void DemoSingleton()
{
    std::cout << "Design Patterns - Creational: Singleton demo\n";
    Singleton& singleton = Singleton::Instance();
    singleton.DoSomething();
}

int main()
{
    DemoSingleton();
    DemoFactoryMethod();
    return 0;
}
