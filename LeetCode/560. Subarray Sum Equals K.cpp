class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            nums[i] = sum;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == k) {
                ans++;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] - nums[i] == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};