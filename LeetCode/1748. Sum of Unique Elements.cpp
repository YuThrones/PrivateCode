class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101, 0);
        for(int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(count[nums[i]] == 1) {
                sum += nums[i];
            }
        }
        return sum;
    }
};