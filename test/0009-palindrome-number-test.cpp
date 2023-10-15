#include <catch2/catch_test_macros.hpp>
#include "0009-palindrom-number.h"

TEST_CASE("Simple cases", "[palindromeNumber]") {
  REQUIRE(isPalindrome(1));
  REQUIRE(isPalindrome(11));
  REQUIRE(isPalindrome(121));
  REQUIRE(isPalindrome(1221));
  REQUIRE(isPalindrome(12321));
  REQUIRE(isPalindrome(123321));
}

TEST_CASE("Negative cases", "[palindromeNumber]") {
  REQUIRE(!isPalindrome(-1));
  REQUIRE(!isPalindrome(-11));
  REQUIRE(!isPalindrome(-121));
  REQUIRE(!isPalindrome(-1221));
  REQUIRE(!isPalindrome(-12321));
  REQUIRE(!isPalindrome(-123321));
}

TEST_CASE("False cases", "[palindromeNumber]") {
  REQUIRE(!isPalindrome(12));
  REQUIRE(!isPalindrome(21));
  REQUIRE(!isPalindrome(112));
  REQUIRE(!isPalindrome(221));
  REQUIRE(!isPalindrome(123));
  REQUIRE(!isPalindrome(321));
}
