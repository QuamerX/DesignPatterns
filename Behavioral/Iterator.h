#pragma once

class FibonacciRange
{
public:
    class Iterator
    {
        int a = 0, b = 1;
    public:
        int operator*() const { return a; }
        Iterator& operator++() { int tmp = a; a = b; b += tmp; return *this; }
        bool operator!=(const Iterator&) const { return a < 100; } // stop at 100
    };

    Iterator begin() { return {}; }
    Iterator end() { return {}; }
};
