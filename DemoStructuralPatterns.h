#pragma once
#include <utility>
#include "Structural/Adapter.h"
#include "Structural/Bridge.h"
#include "Structural/Composite.h"
#include "Structural/Decorator.h"

using namespace Structural;

void DemoAdapter()
{
	std::cout << "Design Patterns - Structural: Adapter demo\n";
	UDPAdapter udpAdapter;
	SerialAdapter serialAdapter;
	SharedMemoryAdapter sharedMemoryAdapter;

	Client client(&udpAdapter);
	client.SendMessage("Hello via UDP!");
	client.ChangeAdapter(&serialAdapter);
	client.SendMessage("Hello via Serial!");
	client.ChangeAdapter(&sharedMemoryAdapter);
	client.SendMessage("Hello via Shared Memory!");
	std::cout << "--------------------------------------------\n";
}

void DemoBridge()
{
	std::cout << "Design Patterns - Structural: Bridge demo\n";
	Circle circle(std::move(std::make_unique<RedColor>()), std::move(std::make_unique<SolidBorder>()));
	Square square(std::move(std::make_unique<BlueColor>()), std::move(std::make_unique<DashedBorder>()));
	Triangle triangle(std::move(std::make_unique<RedColor>()), std::move(std::make_unique<DashedBorder>()));
	circle.Draw();
	square.Draw();
	triangle.Draw();
	std::cout << "--------------------------------------------\n";
}

void DemoComposite()
{
	std::cout << "Design Patterns - Structural: Composite demo\n";
	auto leaf1 = std::make_unique<SimpleData>(1001);
	auto subComposite = std::make_unique<ComplexObject>("HeaderSection");
	subComposite->add(std::make_unique<SimpleData>(42));
	subComposite->add(std::make_unique<SimpleData>(99));
	auto rootComposite = std::make_unique<ComplexObject>("RootDocument");
	rootComposite->add(std::move(leaf1));
	rootComposite->add(std::move(subComposite));
	rootComposite->add(std::make_unique<SimpleData>(2025));
	std::vector<uint8_t> totalSerializedData = rootComposite->Serialize();

	std::cout << "\n------------------------------------------------------\n";
	std::cout << "Total size of the entire serialized object graph: "
		<< totalSerializedData.size() << " bytes.\n";
	std::cout << "------------------------------------------------------\n";
}

void DemoDecorator()
{
	std::cout << "Design Patterns - Structural: Decorator demo\n";
	std::shared_ptr<Coffee> myCoffee = std::make_shared<SimpleCoffee>();
	std::cout << "Order 1: " << myCoffee->GetDescription() << ", Cost: " << myCoffee->GetCost() << std::endl;
	myCoffee = std::make_shared<MilkDecorator>(myCoffee);
	std::cout << "Order 2: " << myCoffee->GetDescription()<< ", Cost: " << myCoffee->GetCost() << std::endl;
	myCoffee = std::make_shared<SugarDecorator>(myCoffee);
	std::cout << "Order 3: " << myCoffee->GetDescription()<< ", Cost: " << myCoffee->GetCost() << std::endl;
	std::cout << "------------------------------------------------------\n";
}

void DemoStructuralPatterns()
{
	DemoAdapter();
	DemoBridge();
	DemoComposite();
	DemoDecorator();
}