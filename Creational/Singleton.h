#pragma once
#include <iostream>

namespace Creational
{

	/**
	 * @brief Singleton creational pattern (Meyers' singleton).
	 *
	 * This class provides a single shared instance accessible via
	 * `Singleton::Instance()`. The instance is lazily-initialized
	 * in a thread-safe way using a function-local static (guaranteed
	 * to be initialized once since C++11).
	 */
	class Singleton
	{
	public:
		/**
		 * @brief Get the shared Singleton instance.
		 *
		 * The function-local static ensures lazy initialization and
		 * thread-safety (since C++11). Returns a reference to the
		 * single global instance.
		 */
		static Singleton& Instance()
		{
			static Singleton inst;
			return inst;
		}

		/**
		 * @brief Example operation on the Singleton.
		 */
		void DoSomething() const
		{
			std::cout << "Singleton: doing something\n";
		}

	private:
		/**
		 * @brief Defaulted default constructor.
		 *
		 * The `= default` syntax tells the compiler to generate the
		 * default implementation. It is equivalent to providing an
		 * implicitly-defined constructor but explicit here to convey intent.
		 */
		Singleton() = default;

		/**
		 * @brief Defaulted destructor.
		 */
		~Singleton() = default;

		/**
		 * @brief Deleted copy constructor.
		 *
		 * The `= delete` syntax prevents the use of this constructor.
		 * Attempting to copy a `Singleton` will be a compile-time error,
		 * ensuring there can only be one instance.
		 */
		Singleton(const Singleton&) = delete;

		/**
		 * @brief Deleted copy assignment operator.
		 *
		 * Prevents assigning one `Singleton` to another; also a compile-time error.
		 */
		Singleton& operator=(const Singleton&) = delete;

		/**
		 * @brief Deleted move constructor
		 *
		 * Prevents moving one `Singleton` to another; also a compile-time error.
		 */
		Singleton(Singleton&&) = delete;

		/**
		 * @brief Deleted move assignment operator.
		 *
		 * Prevents moving one `Singleton` to another; also a compile-time error.
		 */
		Singleton& operator=(Singleton&&) = delete;
	};

} /* namespace Creational */
