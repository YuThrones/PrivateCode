class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int size = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            size += nums[i * 2];
        }
        vector<int> ans(size, 0);
        int index = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            for (int j = 0; j < nums[i * 2]; ++j) {
                ans[index++] = nums[i * 2 + 1];
            }
        }
        return ans;
    }
};