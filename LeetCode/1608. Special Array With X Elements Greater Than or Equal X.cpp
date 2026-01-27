class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while(x <= nums.size()) {
                if (nums[i] >= x) {
                    if (nums.size() - i == x) {
                        return x;
                    }
                    ++x;
                }
                else {
                    break;
                }
            }
        }
        return -1;
    }
};