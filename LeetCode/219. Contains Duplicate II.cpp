// 简单的哈希字典解决，没啥特别的

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (my_map.find(nums[i]) != my_map.end()) {
                if (i - my_map[nums[i]] <= k) {
                    return true;
                }
            }
            my_map[nums[i]] = i;
        }
        return false;
    }
};