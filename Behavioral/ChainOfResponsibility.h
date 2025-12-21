#pragma once

#include <string>

namespace Behavioral
{
    class Validator
    {
    protected:
        Validator* next = nullptr;

    public:
        Validator* setNext(Validator* n)
        {
            next = n;
            return n;
        }

        bool validate(const std::string& input)
        {
            if (!check(input))
                return false;
            if (next)
                return next->validate(input);
            return true;
        }

        virtual bool check(const std::string& input) = 0;
        virtual ~Validator() = default;
    };

    class NotEmpty : public Validator
    {
    public:
        bool check(const std::string& s) override
        {
            if (s.empty())
            {
                std::cout << "Validate Error! Input is empty!\n";
                return false;
            }
            else
            {
                return true;
            }
        }
    };

    class MinLength : public Validator
    {
        size_t len;
    public:
        MinLength(size_t l) : len(l) {}

        bool check(const std::string& s) override
        {
            if (s.size() < len)
            {
                std::cout << "Validate Error! Size is smaller than " << len << "!\n";
				return false;
            }
            else
            {
                return true;
            }
        }
    };

    class NoSpaces : public Validator
    {
    public:
        bool check(const std::string& s) override
        {
            if (s.find(' ') != std::string::npos)
            {
                std::cout << "Validate Error! Input has space character!\n";
                return false;
            }
            else
            {
                return true;
            }

            return s.find(' ') == std::string::npos;
        }
    };

    class ValidatorChain
    {
    private:
        Validator* head = nullptr;
        Validator* tail = nullptr;

    public:
        void add(Validator* v)
        {
            if (!head)
            {
                head = v;
                tail = v;
            }
            else
            {
                tail = tail->setNext(v);
            }
        }

        bool validate(const std::string& s)
        {
            if (!head) return true;
            return head->validate(s);
        }
    };
} // namespace Behavioral
