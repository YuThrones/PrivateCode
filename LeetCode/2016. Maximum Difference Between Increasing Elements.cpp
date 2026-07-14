class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int last = nums[0];
        int ans = -1;
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] > last) {
                ans = max(ans, nums[i] - last);

            }
            last = min(last, nums[i]);
        }
        return ans;
    }
};