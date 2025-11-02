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
    virtual std::string GetName() const =0;

    /**
     * @brief Example operation provided by the product.
     */
    virtual void Use() const =0;
};

/**
 * @brief Concrete product A.
 */
class ConcreteProductA
 : public Product
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
class ConcreteProductB
 : public Product
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
 * @brief Creator interface that declares the factory method.
 */
class Creator
{
public:
    virtual ~Creator() = default;

    /**
     * @brief Factory method to produce products.
     */
    virtual std::unique_ptr<Product> FactoryMethod() const =0;

    /**
     * @brief Example operation that uses the product created by the factory method.
     */
    void SomeOperation() const
    {
        auto product = FactoryMethod();
        product->Use();
    }
};

/**
 * @brief Concrete creator that returns ConcreteProductA.
 */
class ConcreteCreatorA
 : public Creator
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
class ConcreteCreatorB
 : public Creator
{
public:
    std::unique_ptr<Product> FactoryMethod() const override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

/**
 * @brief Demo helper that shows Factory Method usage.
 *
 * This demo shows both:
 * - using the creator's `SomeOperation()` which calls `FactoryMethod()` internally,
 * - and calling `FactoryMethod()` directly to obtain a product.
 */
inline void DemoFactoryMethod()
{
    std::cout << "Factory Method demo:\n";

    ConcreteCreatorA creatorA;
    std::cout << "- CreatorA.SomeOperation() (uses FactoryMethod internally):\n";
    creatorA.SomeOperation();

    std::cout << "- CreatorA.FactoryMethod() used directly:\n";
    auto productA = creatorA.FactoryMethod();
    productA->Use();

    ConcreteCreatorB creatorB;
    std::cout << "- CreatorB.SomeOperation() (uses FactoryMethod internally):\n";
    creatorB.SomeOperation();

    std::cout << "- CreatorB.FactoryMethod() used directly:\n";
    auto productB = creatorB.FactoryMethod();
    productB->Use();
}

} /* namespace Creational */
