#pragma once

#include <iostream>
#include <vector>
#include <memory>

// Command interface
class Command
{
public:
    virtual void Execute() = 0;
    virtual ~Command() {}
};

// Receiver
class Light
{
public:
    void TurnOn() { std::cout << "Light is ON\n"; }
    void TurnOff() { std::cout << "Light is OFF\n"; }
};

// Concrete Commands
class TurnOnCommand : public Command
{
    Light& light;
public:
    TurnOnCommand(Light& l) : light(l) {}
    void Execute() override { light.TurnOn(); }
};

class TurnOffCommand : public Command
{
    Light& light;
public:
    TurnOffCommand(Light& l) : light(l) {}
    void Execute() override { light.TurnOff(); }
};

// Invoker
class RemoteControl
{
    std::vector<std::unique_ptr<Command>> commands;
public:
    void AddCommand(std::unique_ptr<Command> cmd)
    {
        commands.push_back(std::move(cmd));
    }

    void PressButton(int index)
    {
        if (index >= 0 && index < commands.size())
            commands[index]->Execute();
    }
};