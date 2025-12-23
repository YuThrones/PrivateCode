class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -10000;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - lastOne <= k) {
                    return false;
                }
                lastOne = i;
            }
        }
        return true;
    }
};