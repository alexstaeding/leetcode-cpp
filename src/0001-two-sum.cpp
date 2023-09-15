#include <unordered_map>
#include "0001-two-sum.h"

std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return {it->second, i};
        }
        map[nums[i]] = i;
    }
    return {};
}
