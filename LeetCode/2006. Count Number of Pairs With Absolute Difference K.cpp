class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> count(101, 0);
        for(int n : nums) {
            count[n]++;
        }
        int ans = 0;
        for(int i = 0; i + k < 101; ++i) {
            if (count[i] > 0 && count[i + k] > 0) {
                ans += count[i] * count[i + k];
            }
        }
        return ans;
    }
};