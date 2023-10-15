#include <catch2/catch_test_macros.hpp>
#include "0003-longest-substring.h"

TEST_CASE("Positive Case 1", "[lengthOfLongestSubstring]") {
  std::string s = "abcabcbb";
  int expected = 3;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Positive Case 2", "[lengthOfLongestSubstring]") {
  std::string s = "bbbbb";
  int expected = 1;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Positive Case 3", "[lengthOfLongestSubstring]") {
  std::string s = "pwwkew";
  int expected = 3;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Positive Case 4", "[lengthOfLongestSubstring]") {
  std::string s = "abba";
  int expected = 2;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Edge Case 1: Empty String", "[lengthOfLongestSubstring]") {
  std::string s;
  int expected = 0;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Edge Case 2: Single Character", "[lengthOfLongestSubstring]") {
  std::string s = "a";
  int expected = 1;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}

TEST_CASE("Positive Case 4: Non-Repeating String", "[lengthOfLongestSubstring]") {
  std::string s = "abcdef";
  int expected = 6;
  REQUIRE(lengthOfLongestSubstring(s) == expected);
}
