class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (temp > 0) {
                if (nums[i - 1] < nums[i]) {
                    temp += nums[i];
                }
                else {
                    ans = max(ans, temp);
                    temp = nums[i];
                }
            }
            else {
                temp = nums[i];
            }
        }
        if (temp > 0) {
            ans = max(temp, ans);
        }
        return ans;
    }
};