#include "0005-longest-palindrome.h"

std::string longestPalindrome(const std::string &s) {
  int maxSize = 0;
  int start = 0;
  for (int mid = 0; mid < s.length(); mid++) {
    for (int x : {0, 1}) {
      int left = mid;
      int right = mid + x;
      while (left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
      }
      ++left;
      --right;
      if (right - left + 1 > maxSize) {
        maxSize = right - left + 1;
        start = left;
      }
    }
    if (maxSize >= 2 * (s.length() - mid)) {
      break;
    }
  }
  return s.substr(start, maxSize);
}
