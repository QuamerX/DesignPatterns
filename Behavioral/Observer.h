#pragma once

#include <iostream>
#include <vector>
#include <memory>

// Observer interface
class IObserver
{
public:
    virtual void Update(int value) = 0;
    virtual ~IObserver() = default;
};

// Subject
class Subject
{
    std::vector<IObserver*> observers_;
    int state_ = 0;
public:
    void Attach(IObserver* obs) { observers_.push_back(obs); }
    void Detach(IObserver* obs)
    {
        auto it = std::find(observers_.begin(), observers_.end(), obs);
        if (it != observers_.end())
        {
            observers_.erase(it);
        }
    }

    void SetState(int value)
    {
        state_ = value;
        Notify();
    }

    int GetState() const { return state_; }

private:
    void Notify()
    {
        for (auto obs : observers_)
            obs->Update(state_);
    }
};

// Concrete Observer
class ConcreteObserver : public IObserver
{
    std::string name_;
public:
    ConcreteObserver(const std::string& n) : name_(n) {}
    void Update(int value) override
    {
        std::cout << name_ << " received update: " << value << "\n";
    }
};
