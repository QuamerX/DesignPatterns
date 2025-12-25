#pragma once

#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class Colleague;

// Mediator interface
class Mediator
{
public:
    virtual void notify(Colleague* sender, const std::string& event) = 0;
};

// Colleague base class
class Colleague
{
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* m) : mediator(m) {}
};

// Concrete colleagues
class Button : public Colleague
{
public:
    Button(Mediator* m) : Colleague(m) {}
    void click() { mediator->notify(this, "click"); }
};

class TextBox : public Colleague
{
public:
    TextBox(Mediator* m) : Colleague(m) {}
    void setText(const std::string& text)
    {
        std::cout << "TextBox: " << text << "\n";
    }
};

// Concrete mediator
class Dialog : public Mediator
{
    Button* button;
    TextBox* textBox;
public:
    void setButton(Button* b) { button = b; }
    void setTextBox(TextBox* t) { textBox = t; }

    void notify(Colleague* sender, const std::string& event) override
    {
        if (sender == button && event == "click")
        {
            textBox->setText("Button was clicked!");
        }
    }
};

