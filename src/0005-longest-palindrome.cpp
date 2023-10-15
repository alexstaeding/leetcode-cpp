#include "0005-longest-palindrome.h"

std::string longestPalindrome(const std::string &s) {
  int maxSize = 0;
  std::string maxString;
  for (int mid = 0; mid < s.length(); mid++) {
    int oddRadius = 1;
    while (mid - oddRadius >= 0 && mid + oddRadius < s.length()
        && s.at(mid - oddRadius) == s.at(mid + oddRadius)) {
      oddRadius++;
    }
    oddRadius--;

    int evenRadius = 1;
    while (mid - evenRadius >= 0 && mid + evenRadius - 1 < s.length()
        && s.at(mid - evenRadius) == s.at(mid + evenRadius - 1)) {
      evenRadius++;
    }
    evenRadius--;

    if (oddRadius * 2 + 1 > maxSize) {
      maxSize = oddRadius * 2 + 1;
      maxString = s.substr(mid - oddRadius, 2 * oddRadius + 1);
    }

    if (evenRadius * 2 > maxSize) {
      maxSize = evenRadius * 2;
      maxString = s.substr(mid - evenRadius, 2 * evenRadius);
    }
  }
  return maxString;
}
