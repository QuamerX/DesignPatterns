#pragma once

#include <iostream>
#include <string>
#include <memory>

namespace Structural
{
	// 1. Component Interface
	class Coffee
	{
	public:
		virtual std::string GetDescription() const = 0;
		virtual double GetCost() const = 0;
		virtual ~Coffee() = default;
	};

	// 2. Concrete Component
	class SimpleCoffee final : public Coffee
	{
	public:
		std::string GetDescription() const override
		{
			return "Simple Coffee";
		}

		double GetCost() const override
		{
			return 5.0;
		}
	};

	// 3. Base Decorator (Abstract Decorator)
	class CoffeeDecorator : public Coffee
	{
	protected:
		std::shared_ptr<Coffee> wrappedCoffee;

	public:
		// Decorators must be initialized with a Component
		CoffeeDecorator(std::shared_ptr<Coffee> coffee) : wrappedCoffee(std::move(coffee)) {}

		// Delegating methods to the wrapped object by default
		std::string GetDescription() const override
		{
			return wrappedCoffee->GetDescription();
		}

		double GetCost() const override
		{
			return wrappedCoffee->GetCost();
		}
	};

	// 4. Concrete Decorators
	class MilkDecorator final : public CoffeeDecorator
	{
	public:
		MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

		// Adding milk's description to the base description
		std::string GetDescription() const override
		{
			return wrappedCoffee->GetDescription() + ", Milk";
		}

		// Adding milk's cost to the base cost
		double GetCost() const override
		{
			return wrappedCoffee->GetCost() + 2.0;
		}
	};

	class SugarDecorator final : public CoffeeDecorator
	{
	public:
		SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}

		// Adding sugar's description to the base description
		std::string GetDescription() const override
		{
			return wrappedCoffee->GetDescription() + ", Sugar";
		}

		// Adding sugar's cost to the base cost
		double GetCost() const override
		{
			return wrappedCoffee->GetCost() + 0.5;
		}
	};
}