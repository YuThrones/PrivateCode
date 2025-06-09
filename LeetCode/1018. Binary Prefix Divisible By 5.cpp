class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool> result(nums.size(), false);
        for (int i = 0; i < nums.size(); ++i) {
            num = ((num << 1) + nums[i]) % 5;
            if (num % 5 == 0) {
                result[i] = true;
            }
            // cout << num << " " << result[i] << endl;
        }
        return result;
    }
};