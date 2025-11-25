#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

class MonsterType
{
public:
    std::string name;
    std::string texture;
    int baseHealth;
    MonsterType(const std::string& n, const std::string& t, int h) 
        : name(n), texture(t), baseHealth(h) {}
};

class MonsterFactory
{
public:
    std::shared_ptr<MonsterType> GetType(const std::string& name, const std::string& texture, int baseHealth)
    {
        std::string key = name + texture;
        auto it = types.find(key);
        if (it != types.end())
        {
            return it->second;
        }
        else
        {
            auto type = std::make_shared<MonsterType>(name, texture, baseHealth);
            types[key] = type;
            return type;
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<MonsterType>> types;
};

class Monster
{
public:
    Monster(int px, int py, std::shared_ptr<MonsterType> t)
        : x(px), y(py), type(t) {}

    void Draw() const
    {
        std::cout << "Draw " << type->name << " " << type->texture << " at (" << x << "," << y << ")\n";
    }

private:
    int x, y;
    std::shared_ptr<MonsterType> type;
};