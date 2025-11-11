#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <memory>

namespace Structural
{
    // 1. The Component Interface
    // Declares the common operation (serialize) for both simple and complex objects.
    class ISerialize
    {
    public:
        virtual ~ISerialize() = default;
        virtual std::vector<uint8_t> Serialize() const = 0;
    };

    // 2. The Leaf Implementation
    // Represents a simple object that has no children (no delegation required).
    class SimpleData : public ISerialize
    {
    private:
        int value_;

    public:
        SimpleData(int value) : value_(value) {}


        // Implements the serialization directly for its primitive data.
        std::vector<uint8_t> Serialize() const override
        {
            // In a real application, you would handle endianness and size properly.
            // Here, we simulate serialization by converting the integer directly to bytes.
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&value_);
            std::vector<uint8_t> result(bytes, bytes + sizeof(int));

            std::cout << "[Serializing " << value_ << " - Bytes: " << result.size() << "]\n";
            return result;
        }
    };

    // 3. The Composite Implementation
    // Represents a complex object that holds children (Components) and delegates
    // the serialization call to them, then combines the results.
    class ComplexObject : public ISerialize
    {
    private:
        std::string objectName_;
        // The collection of children (Components).
        std::vector<std::unique_ptr<ISerialize>> children_;

    public:
        ComplexObject(const std::string& name) : objectName_(name) {}

        // Method to manage children (Crucial for the Composite role)
        void add(std::unique_ptr<ISerialize> component)
        {
            children_.push_back(std::move(component));
        }

        // Implements the serialization by delegating the call to all children.
        std::vector<uint8_t> Serialize() const override
        {
            std::cout << "\n--- Starting serialization ---\n";
            std::vector<uint8_t> finalBytes;

            for (const auto& child : children_)
            {
                std::vector<uint8_t> childBytes = child->Serialize();
                finalBytes.insert(finalBytes.end(), childBytes.begin(), childBytes.end());
            }

            std::cout << "--- Finished serialization - Total Bytes: " << finalBytes.size() << " ---\n";
            return finalBytes;
        }
    };
}
