#pragma once
#include <iostream>
#include <memory>
#include <string>

namespace Creational
{

	/**
	 * @brief Product interface for Factory Method pattern.
	 */
	class Product
	{
	public:
		virtual ~Product() = default;

		/**
		 * @brief Return product name.
		 */
		virtual std::string GetName() const = 0;

		/**
		 * @brief Example operation provided by the product.
		 */
		virtual void Use() const = 0;
	};

	/**
	 * @brief Concrete product A.
	 */
	class ConcreteProductA : public Product
	{
	public:
		ConcreteProductA() = default;
		~ConcreteProductA() override = default;

		std::string GetName() const override
		{
			return "ConcreteProductA";
		}

		void Use() const override
		{
			std::cout << "Using " << GetName() << "\n";
		}
	};

	/**
	 * @brief Concrete product B.
	 */
	class ConcreteProductB : public Product
	{
	public:
		ConcreteProductB() = default;
		~ConcreteProductB() override = default;

		std::string GetName() const override
		{
			return "ConcreteProductB";
		}

		void Use() const override
		{
			std::cout << "Using " << GetName() << "\n";
		}
	};

	/**
	 * @brief Concrete product C.
	 */
	class ConcreteProductC : public Product
	{
	public:
		ConcreteProductC() = default;
		~ConcreteProductC() override = default;

		std::string GetName() const override
		{
			return "ConcreteProductC";
		}

		void Use() const override
		{
			std::cout << "Using " << GetName() << "\n";
		}
	};

	/**
	 * @brief Abstract base class that declares the factory method.
	 *
	 * This class is an abstract base (not a pure interface) because it
	 * provides a concrete helper `CreateObjectAndUse()` while requiring
	 * derived classes to implement the pure-virtual `FactoryMethod()`.
	 * The helper demonstrates how the factory method is used by the base
	 * class to obtain and use products without depending on concrete types.
	 */
	class Creator
	{
	public:
		virtual ~Creator() = default;

		/**
		 * @brief Factory method to produce products.
		 */
		virtual std::unique_ptr<Product> FactoryMethod() const = 0;

		/**
		 * @brief Example operation that uses the product created by the factory method.
		 */
		void CreateObjectAndUse() const
		{
			auto product = FactoryMethod();
			product->Use();
		}
	};

	/**
	 * @brief Concrete creator that returns ConcreteProductA.
	 */
	class ConcreteCreatorA : public Creator
	{
	public:
		std::unique_ptr<Product> FactoryMethod() const override
		{
			return std::make_unique<ConcreteProductA>();
		}
	};

	/**
	 * @brief Concrete creator that returns ConcreteProductB.
	 */
	class ConcreteCreatorB : public Creator
	{
	public:
		std::unique_ptr<Product> FactoryMethod() const override
		{
			return std::make_unique<ConcreteProductB>();
		}
	};

	/**
	 * @brief Concrete creator that returns ConcreteProductC.
	 */
	class ConcreteCreatorC : public Creator
	{
	public:
		std::unique_ptr<Product> FactoryMethod() const override
		{
			return std::make_unique<ConcreteProductC>();
		}
	};

} /* namespace Creational */
