class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        unordered_map<int, int> m3;
        for(int n : nums1) {
            m1[n] = 1;
        }
        for(int n : nums2) {
            m2[n] = 1;
        }
        for(int n : nums3) {
            m3[n] = 1;
        }
        vector<int> ans;
        for (auto &it: m2) {
            m1[it.first] += 1;
        }
        for (auto &it: m3) {
            m1[it.first] += 1;
        }
        for (auto &it: m1) {
            if(it.second >= 2) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};