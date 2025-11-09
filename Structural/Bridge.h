#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <utility> // For std::move

/**
 * @namespace Structural::Bridge
 * @brief Implementation of the Bridge Design Pattern with two orthogonal dimensions: Color and Border Style.
 * * Decouples the Shape Abstraction hierarchy from the Implementor (Color/Border) hierarchies.
 */
namespace Structural
{
	// =========================================================================
	// 1. Implementor Hierarchy 1: IColorImplementor (The first Bridge target)
	// =========================================================================

	/**
	 * @brief The Implementor Interface for Color.
	 * * Defines the low-level operation for applying a specific color.
	 */
	class IColorImplementor
	{
	public:
		virtual ~IColorImplementor() = default;
		/**
		 * @brief Returns a string describing the color applied.
		 */
		virtual std::string ApplyColor() const = 0;
	};

	/**
	 * @brief Concrete Implementor for Red Color.
	 */
	class RedColor : public IColorImplementor
	{
	public:
		std::string ApplyColor() const override
		{
			return "applied Red";
		}
	};

	/**
	 * @brief Concrete Implementor for Blue Color.
	 */
	class BlueColor : public IColorImplementor
	{
	public:
		std::string ApplyColor() const override
		{
			return "applied Blue";
		}
	};

	// =========================================================================
	// 2. Implementor Hierarchy 2: IBorderImplementor (The second Bridge target)
	// =========================================================================

	/**
	 * @brief The Implementor Interface for Border Style.
	 */
	class IBorderImplementor
	{
	public:
		virtual ~IBorderImplementor() = default;
		/**
		 * @brief Returns a string describing the border style applied.
		 */
		virtual std::string ApplyBorder() const = 0;
	};

	/**
	 * @brief Concrete Implementor for Solid Border.
	 */
	class SolidBorder : public IBorderImplementor
	{
	public:
		std::string ApplyBorder() const override
		{
			return "with Solid Border";
		}
	};

	/**
	 * @brief Concrete Implementor for Dashed Border.
	 */
	class DashedBorder : public IBorderImplementor
	{
	public:
		std::string ApplyBorder() const override
		{
			return "with Dashed Border";
		}
	};

	// =========================================================================
	// 3. Abstraction Hierarchy (The Client-Facing API)
	// =========================================================================

	/**
	 * @brief The Abstraction base class (Shape).
	 * * It acts as the BRIDGE, holding references to the Implementor interfaces.
	 */
	class ShapeAbstraction
	{
	protected:
		// The BRIDGE 1: Composition relationship to the Color Implementor
		std::unique_ptr<IColorImplementor> colorImplementor_;
		// The BRIDGE 2: Composition relationship to the Border Implementor
		std::unique_ptr<IBorderImplementor> borderImplementor_;

	public:
		/**
		 * @brief Constructor that establishes the bridges.
		 * @param colorImp The concrete Color implementation.
		 * @param borderImp The concrete Border implementation.
		 */
		ShapeAbstraction(std::unique_ptr<IColorImplementor> colorImp,
			std::unique_ptr<IBorderImplementor> borderImp)
			: colorImplementor_(std::move(colorImp)),
			borderImplementor_(std::move(borderImp))
		{
		}

		virtual ~ShapeAbstraction() = default;

		/**
		 * @brief High-level operation that delegates to the Implementors.
		 */
		virtual void Draw() const = 0;
	};

	/**
	 * @brief Refined Abstraction: A Circle shape.
	 */
	class Circle : public ShapeAbstraction
	{
	public:
		using ShapeAbstraction::ShapeAbstraction; // Inherit base constructors

		void Draw() const override
		{
			std::cout << "Drawing Circle, "
				<< colorImplementor_->ApplyColor() << ", "
				<< borderImplementor_->ApplyBorder() << "\n";
		}
	};

	/**
	 * @brief Refined Abstraction: A Square shape.
	 */
	class Square : public ShapeAbstraction
	{
	public:
		using ShapeAbstraction::ShapeAbstraction; // Inherit base constructors

		void Draw() const override
		{
			std::cout << "Drawing Square, "
				<< colorImplementor_->ApplyColor() << ", "
				<< borderImplementor_->ApplyBorder() << "\n";
		}
	};

	/**
	 * @brief Refined Abstraction: A Triangle shape.
	 */
	class Triangle : public ShapeAbstraction
	{
	public:
		using ShapeAbstraction::ShapeAbstraction; // Inherit base constructors

		void Draw() const override
		{
			std::cout << "Drawing Triangle, "
				<< colorImplementor_->ApplyColor() << ", "
				<< borderImplementor_->ApplyBorder() << "\n";
		}
	};

}