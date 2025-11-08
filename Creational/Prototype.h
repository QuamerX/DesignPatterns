#pragma once
#include <iostream>
#include <memory>
#include <string>

namespace Creational
{

    /**
     * @brief Prototype pattern example.
     *
     * Shows how to create object copies (clones) without coupling code to
     * concrete classes. Each Prototype provides a `Clone()` operation that
     * returns a polymorphic copy.
     */
    class Prototype
    {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~Prototype() = default;

        /**
         * @brief Clone the current object and return ownership of the copy.
         *
         * @return std::unique_ptr<Prototype> A polymorphic copy of the object.
         */
        virtual std::unique_ptr<Prototype> Clone() const = 0;

        /**
         * @brief Describe the current object.
         *
         * Outputs object details to the standard output.
         */
        virtual void Describe() const = 0;
    };

    /**
     * @brief A concrete prototype with more complex internal state.
     *
     * Implements the Prototype interface and supports deep cloning
     * of its dynamically allocated array.
     */
    class GameCharacter : public Prototype
    {
    public:
        /**
         * @brief Construct a new GameCharacter object.
         *
         * @param name Name of the character.
         * @param allocateSize Size of the internal array to allocate.
         */
        GameCharacter(std::string name, uint8_t allocateSize)
            : name_(std::move(name)), allocateSize_(allocateSize)
        {
            array_ = std::make_unique<uint8_t[]>(allocateSize_);
            for (uint8_t i = 0; i < allocateSize_; i++)
            {
                array_[i] = i;
            }
        }

        /* Rule of Five */
        ~GameCharacter() override = default;                         /**< Default destructor */
        GameCharacter(const GameCharacter&) = delete;               /**< Copy constructor deleted */
        GameCharacter& operator=(const GameCharacter&) = delete;    /**< Copy assignment deleted */
        GameCharacter(GameCharacter&&) = default;                   /**< Move constructor defaulted */
        GameCharacter& operator=(GameCharacter&&) = default;        /**< Move assignment defaulted */

        /**
         * @brief Clone this GameCharacter object.
         *
         * Performs a deep copy of the internal array to ensure unique ownership.
         *
         * @return std::unique_ptr<Prototype> A new cloned GameCharacter.
         */
        std::unique_ptr<Prototype> Clone() const override
        {
            std::unique_ptr<GameCharacter> cloned_character = std::make_unique<GameCharacter>(this->name_, this->allocateSize_);
            cloned_character->array_ = std::make_unique<uint8_t[]>(allocateSize_);
            std::copy(array_.get(), array_.get() + allocateSize_, cloned_character->array_.get());
            return cloned_character;
        }

        /**
         * @brief Output the character's description and array contents.
         */
        void Describe() const override
        {
            std::cout << "GameCharacter name = " << name_ << " allocated elements: \n";
            for (uint8_t i = 0; i < allocateSize_; i++)
            {
                std::cout << "Value " << std::to_string(i) << ": " << std::to_string(array_[i]) << "\n";
            }
        }

        /**
         * @brief Set a new name for the character.
         *
         * @param n New name to assign.
         */
        void SetName(const std::string& n)
        {
            name_ = n;
        }

        /**
         * @brief Update a value in the internal array.
         *
         * @param index Position to update (0-based). Ignored if out of bounds.
         * @param value New value to set at the given index.
         */
        void UpdateArray(uint8_t index, uint8_t value)
        {
            if (index < allocateSize_)
            {
                array_[index] = value;
            }
        }

    private:
        std::unique_ptr<uint8_t[]> array_;   /**< Internal array storing data */
        std::string name_ = "unnamed";       /**< Name of the character */
        uint8_t allocateSize_ = 0;           /**< Size of the internal array */
    };

} /* namespace Creational */
