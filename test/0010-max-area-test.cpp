#include <catch2/catch_test_macros.hpp>
#include "0010-max-area.h"

TEST_CASE("Example 1", "[maxArea]") {
  REQUIRE(maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
}

TEST_CASE("Example 2", "[maxArea]") {
  REQUIRE(maxArea({1, 1}) == 1);
}

TEST_CASE("Descending heights", "[maxArea]") {
  REQUIRE(maxArea({7, 6, 5, 4, 3, 2, 1}) == 12);
}

TEST_CASE("Ascending heights", "[maxArea]") {
  REQUIRE(maxArea({1, 2, 3, 4, 5, 6, 7}) == 12);
}

TEST_CASE("Constant height", "[maxArea]") {
  REQUIRE(maxArea({5, 5, 5, 5, 5}) == 20);
}

TEST_CASE("Single element", "[maxArea]") {
  REQUIRE(maxArea({2}) == 0);
}

TEST_CASE("Two elements with different heights", "[maxArea]") {
  REQUIRE(maxArea({2, 1}) == 1);
}

TEST_CASE("Empty container", "[maxArea]") {
  REQUIRE(maxArea({}) == 0);
}

TEST_CASE("All zero heights", "[maxArea]") {
  REQUIRE(maxArea({0, 0, 0, 0}) == 0);
}
