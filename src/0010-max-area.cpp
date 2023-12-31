#include "0010-max-area.h"

int maxArea(const std::vector<int> &height) {
  if (height.empty()) {
    return 0;
  }
  int low = 0;
  int high = height.size() - 1;
  int result = 0;
  while (low != high) {
    int area = std::min(height[low], height[high]) * (high - low);
    if (area > result) {
      result = area;
    }
    if (height[low] < height[high]) {
      low++;
    } else {
      high--;
    }
  }
  return result;
}
