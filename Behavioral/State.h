#pragma once

#include <iostream>
#include <memory>

class Context; // Forward declaration

// State interface
class State
{
public:
    virtual void handle(Context& context) = 0;
    virtual ~State() = default;
};

// Concrete States
class Red : public State
{
public:
    void handle(Context& context) override;
};

class Green : public State
{
public:
    void handle(Context& context) override;
};

class Yellow : public State
{
public:
    void handle(Context& context) override;
};

// Context
class Context
{
private:
    std::shared_ptr<State> state_;
public:
    void setState(std::shared_ptr<State> state) { state_ = state; }
    void request() { if (state_) state_->handle(*this); }
};

// Implementations
void Red::handle(Context& context)
{
    std::cout << "Red Light\n";
    context.setState(std::make_shared<Green>());
}

void Green::handle(Context& context)
{
    std::cout << "Green Light\n";
    context.setState(std::make_shared<Yellow>());
}

void Yellow::handle(Context& context)
{
    std::cout << "Yellow Light\n";
    context.setState(std::make_shared<Red>());
}
