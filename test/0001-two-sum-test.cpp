#include <catch2/catch_test_macros.hpp>
#include "0001-two-sum.h"

TEST_CASE("Positive Case 1", "[twoSum]") {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected = {0, 1};
    REQUIRE(twoSum(nums, target) == expected);
}

TEST_CASE("Positive Case 2", "[twoSum]") {
    std::vector<int> nums = {3, 2, 4};
    int target = 6;
    std::vector<int> expected = {1, 2};
    REQUIRE(twoSum(nums, target) == expected);
}

TEST_CASE("Negative Case", "[twoSum]") {
    std::vector<int> nums = {1, 2, 3, 4};
    int target = 10;
    std::vector<int> expected = {};
    REQUIRE(twoSum(nums, target) == expected);
}
