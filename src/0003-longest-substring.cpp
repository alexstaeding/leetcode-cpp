#include <set>
#include "0003-longest-substring.h"

int lengthOfLongestSubstring(const std::string &s) {
  int low = 0;
  int maxDiff = 0;
  std::set<char> set;

  for (int high = 0; high < s.length(); high++) {
    char c = s.at(high);
    while (set.contains(c)) {
      char removedChar = s.at(low++);
      set.erase(removedChar);
      if (removedChar == c) {
        break;
      }
    }
    set.insert(c);
    if (high - low + 1 > maxDiff) {
      maxDiff = high - low + 1;
    }
  }
  return maxDiff;
}
