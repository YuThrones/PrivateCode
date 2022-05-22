// 直接想到的就是数组直接存储所有位置是否用过就行，看了下最快答案，事实上可以对整个数组求和，然后和0到n的和一减就知道答案了

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n + 1, 0);
        for (auto i: nums) temp[i] = 1;
        for (int i = 0; i <= n; ++i) {
            if (!temp[i]) return i;
        }
        return 0;
    }
};