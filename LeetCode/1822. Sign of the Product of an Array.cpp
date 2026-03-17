class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = signFunc(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            ans *= signFunc(nums[i]);
        }
        return ans;
    }

    int signFunc(int x) {
        if (x > 0) {return 1;}
        if (x < 0) {return -1;}
        return 0;
    }
};