class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minNum = 0;
        for(int n : nums) {
            sum += n;
            minNum = min(minNum, sum);
        }
        return 1 - minNum;
    }
};