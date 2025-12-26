#pragma once

#include <iostream>

class _Circle;
class Rectangle;

class ShapeVisitor
{
public:
    virtual void Visit(_Circle&) = 0;
    virtual void Visit(Rectangle&) = 0;
};

class Shape
{
public:
    virtual void Accept(ShapeVisitor& v) = 0;
};

class _Circle : public Shape
{
public:
    void Accept(ShapeVisitor& v) override
    {
        v.Visit(*this);
    }

    int radius = 5;
};

class Rectangle : public Shape
{
public:
    void Accept(ShapeVisitor& v) override
    {
        v.Visit(*this);
    }

    int w = 3, h = 4;
};

class AreaCalculator : public ShapeVisitor
{
public:
    void Visit(_Circle& c) override
    {
        std::cout << "Circle area: " << 3.14 * c.radius * c.radius << "\n";
    }

    void Visit(Rectangle& r) override
    {
        std::cout << "Rectangle area: " << r.w * r.h << "\n";
    }
};
