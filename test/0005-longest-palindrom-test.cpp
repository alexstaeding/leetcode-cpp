#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "0005-longest-palindrome.h"

TEST_CASE("Empty case", "[longestPalindrome]") {
  REQUIRE(longestPalindrome("").empty());
}

TEST_CASE("Odd case 1", "[longestPalindrome]") {
  REQUIRE(longestPalindrome("aba") == "aba");
}

TEST_CASE("Odd case 2", "[longestPalindrome]") {
  REQUIRE(longestPalindrome("cabad") == "aba");
}

TEST_CASE("Even case 1", "[longestPalindrome]") {
  REQUIRE(longestPalindrome("aa") == "aa");
}

TEST_CASE("Even case 2", "[longestPalindrome]") {
  REQUIRE(longestPalindrome("baacffcagh") == "acffca");
}
