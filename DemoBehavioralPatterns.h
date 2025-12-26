#pragma once
#include "Behavioral/ChainOfResponsibility.h"
#include "Behavioral/Command.h"
#include "Behavioral/Iterator.h"
#include "Behavioral/Mediator.h"
#include "Behavioral/Observer.h"
#include "Behavioral/Memento.h"
#include "Behavioral/State.h"
#include "Behavioral/Strategy.h"
#include "Behavioral/TemplateMethod.h"
#include "Behavioral/Visitor.h"

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

void DemoCommand()
{
	std::cout << "Design Patterns - Behavioral: Command Pattern demo\n";
	Light light;
	RemoteControl remote;
	remote.AddCommand(std::make_unique<TurnOnCommand>(light));
	remote.AddCommand(std::make_unique<TurnOffCommand>(light));
	remote.PressButton(0); // Turn on the light
	remote.PressButton(1); // Turn off the light
	std::cout << "--------------------------------------------\n";
}

void DemoIterator()
{
	std::cout << "Design Patterns - Behavioral: Iterator Pattern demo\n";
	FibonacciRange fibRange;
	for (int num : fibRange)
	{
		std::cout << num << " ";
	}
	std::cout << "\n--------------------------------------------\n";
}

void DemoMediator()
{
	std::cout << "Design Patterns - Behavioral: Mediator Pattern demo\n";
	Dialog dialog;
	Button button(&dialog);
	TextBox textBox(&dialog);
	dialog.setButton(&button);
	dialog.setTextBox(&textBox);
	button.click();
	std::cout << "--------------------------------------------\n";
}

void DemoObserver()
{
	std::cout << "Design Patterns - Behavioral: Observer Pattern demo\n";
	Subject subject;
	ConcreteObserver obs1("Observer1");
	ConcreteObserver obs2("Observer2");
	subject.Attach(&obs1);
	subject.Attach(&obs2);
	subject.SetState(10);
	subject.SetState(20);
	subject.Detach(&obs1);
	subject.SetState(30);
	std::cout << "--------------------------------------------\n";
}

void DemoMemento()
{
	std::cout << "Design Patterns - Behavioral: Memento Pattern demo\n";
	Originator originator;
	Caretaker caretaker;
	originator.setState(1);
	caretaker.addMemento(originator.save());
	originator.setState(2);
	caretaker.addMemento(originator.save());
	originator.setState(3);
	caretaker.addMemento(originator.save());
	originator.restore(caretaker.getMemento(0));
	originator.restore(caretaker.getMemento(1));
	originator.restore(caretaker.getMemento(2));
	std::cout << "--------------------------------------------\n";
}

void DemoState()
{
	std::cout << "Design Patterns - Behavioral: State Pattern demo\n";
	Context trafficLight;
	trafficLight.setState(std::make_shared<Red>());
	for (int i = 0; i < 6; ++i)
	{
		trafficLight.request();
	}
	std::cout << "--------------------------------------------\n";
}

void DemoStrategy()
{
	std::cout << "Design Patterns - Behavioral: Strategy Pattern demo\n";
	std::vector<int> data1 = { 5, 3, 8, 1, 2 };
	std::vector<int> data2 = { 5, 3, 8, 1, 2 };
	BubbleSort bubble;
	QuickSort quick;
	Sorter sorter;
	sorter.setStrategy(&bubble);
	sorter.sort(data1);
	sorter.setStrategy(&quick);
	sorter.sort(data2);
	std::cout << "\n--------------------------------------------\n";
}

void DemoTemplateMethod()
{
	std::cout << "Design Patterns - Behavioral: Template Method Pattern demo\n";
	CSVProcessor csvProcessor;
	JSONProcessor jsonProcessor;
	csvProcessor.process();
	jsonProcessor.process();
	std::cout << "--------------------------------------------\n";
}

void DemoVisitor()
{
	std::cout << "Design Patterns - Behavioral: Visitor Pattern demo\n";
	_Circle c;
	Rectangle r;
	AreaCalculator area;
	c.Accept(area);
	r.Accept(area);
	std::cout << "--------------------------------------------\n";
}

void DemoBehavioralPatterns()
{
	DemoChainOfResponsibility();
	DemoCommand();
	DemoIterator();
	DemoMediator();
	DemoObserver();
	DemoMemento();
	DemoState();
	DemoStrategy();
	DemoTemplateMethod();
	DemoVisitor();
}