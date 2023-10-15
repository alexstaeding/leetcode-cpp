#include <unordered_map>
#include "0003-longest-substring.h"

int lengthOfLongestSubstring(const std::string &s) {
  int low = 0;
  int maxDiff = 0;
  std::unordered_map<char, int> map;

  for (int high = 0; high < s.length(); high++) {
    char c = s.at(high);

    if (map.find(c) != map.end()) {
      low = std::max(low, map[c] + 1);
    }

    map[c] = high;

    if (high - low + 1 > maxDiff) {
      maxDiff = high - low + 1;
    }
  }
  return maxDiff;
}
