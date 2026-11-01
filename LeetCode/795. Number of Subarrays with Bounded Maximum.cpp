class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long ans = 0;
        int lastInvalid = -1; // 最近一个 > right 的位置
        int lastValid = -1;   // 最近一个在 [left, right] 中的位置

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                lastInvalid = i;
            } else if (nums[i] >= left) {
                lastValid = i;
            }

            if (lastValid > lastInvalid) {
                ans += lastValid - lastInvalid;
            }
        }

        return ans;
    }
};