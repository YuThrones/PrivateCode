class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) {
            return true;
        }
        bool increasing  = (nums[0] <= nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); ++i) {
            if (increasing ) {
                if (nums[i - 1] > nums[i]) {
                    return false;
                }
            }
            else {
                if (nums[i - 1] < nums[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};