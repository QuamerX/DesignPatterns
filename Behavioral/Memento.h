#pragma once

#include <iostream>
#include <vector>
#include <memory>

// Memento: stores state
class Memento
{
private:
    int state_;
public:
    Memento(int state) : state_(state) {}
    int getState() const { return state_; }
};

// Originator: creates and restores mementos
class Originator
{
private:
    int state_;
public:
    void setState(int state)
    {
        state_ = state;
        std::cout << "State set to " << state_ << std::endl;
    }
    int getState() const { return state_; }

    std::shared_ptr<Memento> save()
    {
        return std::make_shared<Memento>(state_);
    }

    void restore(std::shared_ptr<Memento> memento)
    {
        state_ = memento->getState();
        std::cout << "State restored to " << state_ << std::endl;
    }
};

// Caretaker: keeps mementos
class Caretaker
{
private:
    std::vector<std::shared_ptr<Memento>> history_;
public:
    void addMemento(std::shared_ptr<Memento> memento)
    {
        history_.push_back(memento);
    }

    std::shared_ptr<Memento> getMemento(size_t index)
    {
        if (index < history_.size()) return history_[index];
        return nullptr;
    }
};
