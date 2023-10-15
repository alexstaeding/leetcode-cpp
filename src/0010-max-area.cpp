#include "0010-max-area.h"

int maxArea(const std::vector<int> &height) {
  int low = 0;
  int high = height.size() - 1;
  int result = 0;
  while (low != high) {
    int area = std::min((int) height[low], (int) height[high]) * (high - low);
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
