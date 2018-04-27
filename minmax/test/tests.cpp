#include "main.hpp"
#include <cstdlib>
#include <iostream>
#include <type_traits>

struct Ordered_t {
    int x;
    int y;
    friend bool operator<(const Ordered_t&, const Ordered_t&);
};

bool operator<(const Ordered_t& a, const Ordered_t& b) { return a.x < b.x; }

void run_tests()
{
    {
        int x = 42;
        int y = 11;

        // test for built-in types
        if (min(x, y) != 11 || min(y, x) != 11) {
            std::cout << "min(int, int) returns wrong value\n";
            std::exit(1);
        }

        if (max(x, y) != 42 || max(y, x) != 42) {
            std::cout << "max(int, int) returns wrong value\n";
            std::exit(1);
        }

        // test for references
        min(x, y) = 12;
        if (y != 12) {
            std::cout << "min() does not use references\n";
            std::exit(1);
        }
        max(x, y) = 43;
        if (x != 43) {
            std::cout << "max() does not use references\n";
            std::exit(1);
        }
    }

    {
        Ordered_t x{10, 20};
        Ordered_t y{11, 20};

        // test if correct comparison operator is used
        if (min(x, y).x != x.x) {
            std::cout << "min(Ordered, Ordered) returns wrong value\n";
            std::exit(1);
        }

        if (max(x, y).x != y.x) {
            std::cout << "max(Ordered, Ordered) returns wrong value\n";
            std::exit(1);
        }
    }

#ifdef RVALUES
    {
        static_assert(std::is_rvalue_reference<decltype(min(10, 21))>::value,
                      "min() does not return an rvalue reference");
        // test if rvalues work
        if (min(10, 21) != 10) {
            std::cout << "min(rvalue, rvalue) returns wrong value for rvalue "
                         "inputs\n";
            std::exit(1);
        }

        if (max(10, 21) != 21) {
            std::cout << "max(rvalue, rvalue) returns wrong value for rvalue "
                         "inputs\n";
            std::exit(1);
        }
    }
#endif /* RVALUES */
    std::cout << "All tests run succesfullly.\n";
}
