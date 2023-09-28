#include "0167-two-sum-sorted.h"

std::vector<int> twoSumSorted(std::vector<int> &numbers, int target) {
  int start = 0;
  int end = numbers.size() - 1;
  while (true) {
    if (numbers[start] + numbers[end] > target) {
      --end;
    } else if (numbers[start] + numbers[end] == target) {
      return {start + 1, end + 1};
    } else {
      ++start;
    }
  }
}
