#include "point.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include "tests.hpp"
#include "point.hpp"

int main()
{
    static constexpr std::size_t length = 20;
    std::vector<int> nums(length);
    std::vector<Point> points(length);
    std::srand(std::time(nullptr));
    for (auto &i : nums) {
        i = std::rand() % 1024;
    }
    for (auto &p : points) {
        p.x = std::rand() % 256;
        p.y = std::rand() % 1024;
        p.z = std::rand() % 128;
    }

    // sort nums in ascending order
  
    // sort points in descending order by the y coordinate
    
    run_tests(nums, points);
    return 0;
}
