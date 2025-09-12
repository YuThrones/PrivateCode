class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int digits = 0;
            while(n > 0) {
                ++digits;
                n /= 10;
            }
            if (digits % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};