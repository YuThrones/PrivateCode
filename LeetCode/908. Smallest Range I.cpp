class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int minNum = nums[0];
        int maxNum = nums[0];
        for (auto n : nums) {
            minNum = min(n, minNum);
            maxNum = max(n, maxNum);
        }
        int diff = maxNum - minNum;
        if (diff < k * 2) {
            return 0;
        }
        return diff - k * 2;
    }
};