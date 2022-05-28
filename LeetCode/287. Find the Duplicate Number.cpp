// 最简单肯定一个哈希表解决问题，看了下最快答案，利用了nums[i] <= nums.size()，用一个vector来计算，确实要更快

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n: nums) {
            if (s.find(n) != s.end()) return n;
            s.insert(n);
        }
        return 0;
    }
};