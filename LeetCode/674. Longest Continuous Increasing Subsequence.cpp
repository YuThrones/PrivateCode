class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {return 0;}
        int res = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                res = max(res, count);
                count = 1;
            }
            else {
                ++count;
            }
        }
        res = max(res, count);
        return res;
    }
};