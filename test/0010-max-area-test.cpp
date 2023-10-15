#include <catch2/catch_test_macros.hpp>
#include "0010-max-area.h"

TEST_CASE("Example 1", "[maxArea]") {
  REQUIRE(maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
}

TEST_CASE("Example 2", "[maxArea]") {
  REQUIRE(maxArea({1, 1}) == 1);
}
