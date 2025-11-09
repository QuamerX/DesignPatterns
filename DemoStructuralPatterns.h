#pragma once
#include <utility>
#include "Structural/Adapter.h"
#include "Structural/Bridge.h"

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

void DemoStructuralPatterns()
{
	DemoAdapter();
	DemoBridge();
}