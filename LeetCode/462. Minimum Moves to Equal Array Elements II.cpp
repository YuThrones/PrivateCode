class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = 0;
        if (nums.size() % 2 == 0) {
            mid = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
        }
        else {
            mid = nums[nums.size() / 2];
        }
        return cal(nums, mid);
    }

    int cal(vector<int>& nums, int target) {
        int ans = 0;
        for (int n : nums) {
            ans += abs(n - target);
        }
        return ans;
    }
};