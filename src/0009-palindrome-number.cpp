#include <string>
#include "0009-palindrom-number.h"

int num_digits(uint32_t x) {
  if (x >= 10000) {
    if (x >= 10000000) {
      if (x >= 100000000) {
        if (x >= 1000000000)
          return 10;
        return 9;
      }
      return 8;
    }
    if (x >= 100000) {
      if (x >= 1000000)
        return 7;
      return 6;
    }
    return 5;
  }
  if (x >= 100) {
    if (x >= 1000)
      return 4;
    return 3;
  }
  if (x >= 10)
    return 2;
  return 1;
}

int pow10(int n) {
  static int pow10[10] = {
      1, 10, 100, 1000, 10000,
      100000, 1000000, 10000000, 100000000, 1000000000
  };

  return pow10[n];
}

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  int n = num_digits(x);
  if (n == 1) {
    return true;
  }
  for (int i = 0; i < n / 2; ++i) {
    if ((x / pow10(n - i - 1)) % 10 != (x % pow10(i + 1)) / pow10(i)) {
      return false;
    }
  }
  return true;
}

bool isPalindromeAlt(int x) {
  std::string a = std::to_string(x);
  std::string b = a.substr(0, a.length() / 2);
  std::reverse(b.begin(), b.end());
  return std::equal(b.begin(), b.end(), a.begin() + (a.length() - b.length()));
}
