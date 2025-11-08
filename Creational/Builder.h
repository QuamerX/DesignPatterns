#pragma once
#include <iostream>
#include <string>
#include <vector>

/**
 * @file
 * @brief Sandwich builder example (nested Builder) with Doxygen documentation.
 *
 * This header provides a `Sandwich` product type and a nested `Sandwich::Builder`
 * that can be used to construct `Sandwich` instances using a fluent API.
 */

class Sandwich
{
private:
    std::string _bread;
    std::string _meat;
    std::vector<std::string> _veggies;
    bool _toasted = false;

    /**
     * @brief Private constructor used by the Builder to create a Sandwich.
     *
     * @param bread Bread type.
     * @param meat Meat type.
     * @param veggies List of vegetables/toppings.
     * @param toasted Whether the sandwich is toasted.
     */
    Sandwich(const std::string& bread, const std::string& meat,
        const std::vector<std::string>& veggies, bool toasted)
        : _bread(bread), _meat(meat), _veggies(veggies), _toasted(toasted) {}

public:
    /**
     * @brief Print a human-readable description of the assembled sandwich.
     */
    void Describe() const
    {
        std::cout << "--- Final Sandwich ---\n";
        std::cout << "Bread: " << _bread << (_toasted ? " (TOASTED)" : "") << std::endl;
        std::cout << "Meat: " << _meat << std::endl;
        std::cout << "Veggies: ";
        if (_veggies.empty())
        {
            std::cout << "None";
        }
        else
        {
            for (const auto& v : _veggies)
            {
                std::cout << v << ", ";
            }
        }
        std::cout << "\n----------------------\n";
    }

    /**
     * @brief Builder for `Sandwich`.
     *
     * The builder is nested inside `Sandwich` so it can be referenced as
     * `Sandwich::Builder`. It provides a fluent API to configure ingredients
     * and a `Build()` method to produce a `Sandwich` value.
     */
    class Builder
    {
    private:
        // Builder holds the temporary state/ingredients
        std::string _bread = "White"; ///< Default bread type
        std::string _meat = "None"; ///< Default meat (none)
        std::vector<std::string> _veggies; ///< List of veggies
        bool _toasted = false; ///< Toasted flag

    public:
        Builder() = default;
        ~Builder() = default;

        /**
         * @brief Set the bread type for the sandwich.
         *
         * This method modifies the builder and returns a reference to it to
         * allow method chaining.
         *
         * @param bread Bread type (e.g. "White", "Rye").
         * @return Reference to the builder (for chaining).
         */
        Builder& SetBread(const std::string& bread)
        {
            _bread = bread;
            return *this;
        }

        /**
         * @brief Set the meat for the sandwich.
         *
         * @param meat Meat type (e.g. "Turkey").
         * @return Reference to the builder (for chaining).
         */
        Builder& AddMeat(const std::string& meat)
        {
            _meat = meat;
            return *this;
        }

        /**
         * @brief Add a vegetable/topping to the sandwich.
         *
         * Multiple calls append multiple veggies.
         *
         * @param veggie Single vegetable name (e.g. "Lettuce").
         * @return Reference to the builder (for chaining).
         */
        Builder& AddVeggie(const std::string& veggie)
        {
            _veggies.push_back(veggie);
            return *this;
        }

        /**
         * @brief Set whether the sandwich should be toasted.
         *
         * @param toasted true to toast, false otherwise.
         * @return Reference to the builder (for chaining).
         */
        Builder& SetToasted(bool toasted)
        {
            _toasted = toasted;
            return *this;
        }

        /**
         * @brief Build the final Sandwich instance.
         *
         * Performs lightweight validation and returns a fully constructed
         * `Sandwich` by value. Returning by value is idiomatic for product
         * objects; compilers will typically elide copies (RVO).
         *
         * @return Constructed Sandwich.
         */
        Sandwich Build()
        {
            // No exceptions expected here; warn about an unusually plain sandwich
            if (_meat == "None" && _veggies.empty())
            {
                std::cerr << "Warning: Building a very plain sandwich!\n";
            }

            // Call the private constructor of the outer Sandwich class
            return Sandwich(_bread, _meat, _veggies, _toasted);
        }
    };

    /**
     * @brief Convenience factory to obtain a default-initialized Builder.
     *
     * Usage example:
     * @code{.cpp}
     * auto s = Sandwich::Create()
     * .SetBread("Rye")
     * .AddMeat("Turkey")
     * .AddVeggie("Lettuce")
     * .SetToasted(true)
     * .Build();
     * @endcode
     *
     * @return A Builder object initialized with default values.
     */
    static Builder Create()
    {
        return Builder();
    }
};