class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int temp = 0;
        for(int n : nums) {
            temp += n;
            ans.push_back(n);
            if(temp > total / 2) {
                break;
            }
        }
        return ans;
    }
};