#include <catch2/catch_test_macros.hpp>
#include "0167-two-sum-sorted.h"

TEST_CASE("Positive Case 1", "[twoSumSorted]") {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected = {0, 1};
    REQUIRE(twoSumSorted(nums, target) == expected);
}

TEST_CASE("Negative Case 1", "[twoSumSorted]") {
  std::vector<int> nums = {-1000,-1,0,1};
  int target = 1;
  std::vector<int> expected = {3, 4};
  REQUIRE(twoSumSorted(nums, target) == expected);
}
