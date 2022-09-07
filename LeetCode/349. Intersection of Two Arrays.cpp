// 哈希表加两次遍历，暴力但有效，也可以排序之后从前往后遍历

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> unSet;
        for (auto i: nums1) {
             unSet.insert(i);
        }
        for (auto i: nums2) {
            if (unSet.find(i) != unSet.end()) {
                res.push_back(i);
                unSet.erase(i);
            }
        }
        return res;
    }
};