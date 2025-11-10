#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <memory>

// Define a type alias for the byte array (the serialized output)
using ByteArray = std::vector<uint8_t>;

// Helper function to concatenate two byte arrays
ByteArray concatenate(const ByteArray& a, const ByteArray& b)
{
    ByteArray result = a;
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

// 1. The Component Interface
// Declares the common operation (serialize) for both simple and complex objects.
class ISerialize
{
public:
    virtual ~ISerialize() = default;
    // The main operation: converts the object's data into a byte array.
    virtual ByteArray serialize() const = 0;
    // A helper method for visualization
    virtual std::string getName() const = 0;
};

// 2. The Leaf Implementation
// Represents a simple object that has no children (no delegation required).
class SimpleData : public ISerialize
{
private:
    int value_;

public:
    SimpleData(int value) : value_(value) {}

    std::string getName() const override { return "Leaf (SimpleData)"; }

    // Implements the serialization directly for its primitive data.
    ByteArray serialize() const override
    {
        // In a real application, you would handle endianness and size properly.
        // Here, we simulate serialization by converting the integer directly to bytes.
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&value_);
        ByteArray result(bytes, bytes + sizeof(int));

        std::cout << "[Serializing " << getName() << " with value " << value_ << " - Bytes: " << result.size() << "]\n";
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

    std::string getName() const override { return "Composite (" + objectName_ + ")"; }

    // Method to manage children (Crucial for the Composite role)
    void add(std::unique_ptr<ISerialize> component)
    {
        children_.push_back(std::move(component));
    }

    // Implements the serialization by delegating the call to all children.
    ByteArray serialize() const override
    {
        std::cout << "\n--- Starting serialization of " << getName() << " ---\n";
        ByteArray finalBytes;

        for (const auto& child : children_)
        {
            // Recursive call to serialize, treating Leaf and Composite children uniformly
            ByteArray childBytes = child->serialize();
            finalBytes = concatenate(finalBytes, childBytes);
        }

        std::cout << "--- Finished serialization of " << getName() << " - Total Bytes: " << finalBytes.size() << " ---\n";
        return finalBytes;
    }
};

int demo()
{
    std::cout << "Starting Composite Serialization Demonstration...\n\n";

    // --- Building the Object Hierarchy (The Composite Structure) ---

    // 1. Create a Leaf (simple data)
    auto leaf1 = std::make_unique<SimpleData>(1001);

    // 2. Create a Nested Composite (Sub-container)
    auto subComposite = std::make_unique<ComplexObject>("HeaderSection");
    subComposite->add(std::make_unique<SimpleData>(42));
    subComposite->add(std::make_unique<SimpleData>(99));

    // 3. Create the Root Composite (Main Object)
    auto rootComposite = std::make_unique<ComplexObject>("RootDocument");

    // Add the first Leaf to the Root
    rootComposite->add(std::move(leaf1));

    // Add the Nested Composite (Uniform treatment of Leaf and Composite)
    rootComposite->add(std::move(subComposite));

    // Add one more Leaf directly to the Root
    rootComposite->add(std::make_unique<SimpleData>(2025));

    // --- Client Usage ---
    // The client only needs to call serialize on the top-level object.
    // The complexity of the hierarchy is handled internally and recursively.

    ByteArray totalSerializedData = rootComposite->serialize();

    std::cout << "\n------------------------------------------------------\n";
    std::cout << "Total size of the entire serialized object graph: "
        << totalSerializedData.size() << " bytes.\n";
    std::cout << "------------------------------------------------------\n";

    return 0;
}