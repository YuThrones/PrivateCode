class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        return handle(maxNum, minNum);
    }

    int handle(int large, int small) {
        if (small == 0) {return 0;}
        if (large % small == 0) {
            return small;
        }
        return handle(small, large % small);
    }
};