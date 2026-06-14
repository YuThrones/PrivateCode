// 这道题不是从编程上解决的，一开始没想到，主要是逆序对不能超过1个位置，不然全局的必然更多

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(nums[i] - i) > 1) return false;
        }
        return true;
    }
};