#pragma once
#include <iostream>
#include <memory>
#include <string>

namespace Creational
{

/**
 * @brief Abstract Factory pattern example.
 *
 * This example demonstrates creating related products (ProductX and ProductY)
 * without coupling the client code to concrete product classes. Two concrete
 * factories produce a family of compatible products (Family1 -> ProductX1/ProductY1,
 * Family2 -> ProductX2/ProductY2).
 */

/**
 * @brief Abstract product X.
 */
class AbstractProductX
{
public:
    virtual ~AbstractProductX() = default;

    /**
     * @brief Return product name.
     */
    virtual std::string GetName() const =0;

    /**
     * @brief Example operation.
     */
    virtual void Use() const =0;
};

/**
 * @brief Abstract product Y.
 */
class AbstractProductY
{
public:
    virtual ~AbstractProductY() = default;

    /**
     * @brief Return product name.
     */
    virtual std::string GetName() const =0;

    /**
     * @brief Example operation that may collaborate with product X.
     */
    virtual void InteractWith(const AbstractProductX& x) const =0;
};

/**
 * @brief Concrete ProductX for Family1.
 */
class ProductX1 : public AbstractProductX
{
public:
    ProductX1() = default;
    ~ProductX1() override = default;

    std::string GetName() const override
    {
        return "ProductX1";
    }

    void Use() const override
    {
        std::cout << "Using " << GetName() << "\n";
    }
};

/**
 * @brief Concrete ProductY for Family1.
 */
class ProductY1 : public AbstractProductY
{
public:
    ProductY1() = default;
    ~ProductY1() override = default;

    std::string GetName() const override
    {
        return "ProductY1";
    }

    void InteractWith(const AbstractProductX& x) const override
    {
        std::cout << GetName() << " interacts with " << x.GetName() << "\n";
    }
};

/**
 * @brief Concrete ProductX for Family2.
 */
class ProductX2 : public AbstractProductX
{
public:
    ProductX2() = default;
    ~ProductX2() override = default;

    std::string GetName() const override
    {
        return "ProductX2";
    }

    void Use() const override
    {
        std::cout << "Using " << GetName() << "\n";
    }
};

/**
 * @brief Concrete ProductY for Family2.
 */
class ProductY2 : public AbstractProductY
{
public:
    ProductY2() = default;
    ~ProductY2() override = default;

    std::string GetName() const override
    {
        return "ProductY2";
    }

    void InteractWith(const AbstractProductX& x) const override
    {
        std::cout << GetName() << " interacts with " << x.GetName() << "\n";
    }
};

/**
 * @brief Abstract factory declares creation methods for each product type.
 */
class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;

    virtual std::unique_ptr<AbstractProductX> CreateProductX() const =0;
    virtual std::unique_ptr<AbstractProductY> CreateProductY() const =0;
};

/**
 * @brief Concrete factory producing Family1 products.
 */
class ConcreteFactory1 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductX> CreateProductX() const override
    {
        return std::make_unique<ProductX1>();
    }

    std::unique_ptr<AbstractProductY> CreateProductY() const override
    {
        return std::make_unique<ProductY1>();
    }
};

/**
 * @brief Concrete factory producing Family2 products.
 */
class ConcreteFactory2 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductX> CreateProductX() const override
    {
        return std::make_unique<ProductX2>();
    }

    std::unique_ptr<AbstractProductY> CreateProductY() const override
    {
        return std::make_unique<ProductY2>();
    }
};

} /* namespace Creational */
