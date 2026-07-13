class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for(int n : nums) {
            sum += n;
        }
        int acc = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (acc * 2 + nums[i] == sum) {
                return i;
            }
            acc += nums[i];
        }
        return -1;
    }
};