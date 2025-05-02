class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> count;
        map<int, int> first;
        map<int, int> last;
        int maxNum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
                count[nums[i]] = 1;
            }
            else {
                ++count[nums[i]];
            }
            last[nums[i]] = i;
            maxNum = max(maxNum, count[nums[i]]);
        }
        int result = INT_MAX;
        for (auto it : count) {
            if (it.second == maxNum) {
                result = min(result, last[it.first] - first[it.first] + 1);
            }
        }
        return result;
    }
};