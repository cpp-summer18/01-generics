#pragma once

#include <vector>
#include "point.hpp"
#include <iostream>

template<typename T, typename U>
void run_tests(const T &nums, const U &points)
{
    // nums must be sorted in ascending order
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            std::cerr << "nums is not sorted in ascending order!\n";
            std::exit(1);
        }
    }
    // points must be sorted by y coordinates in descending order
    for (size_t i = 0; i < points.size() - 1; ++i) {
        if (points[i].y < points[i + 1].y) {
            std::cerr << "points is not sorted by Point::y\n";
            std::exit(1);
        }
    }
    std::cout << "All tests run successfully.\n";
}
