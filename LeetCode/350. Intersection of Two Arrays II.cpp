// 还是两种方法，哈希表或者排序解决

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> unSet;
        for (auto i: nums1) {
             unSet[i] += 1;
        }
        for (auto i: nums2) {
            if (unSet[i] > 0) {
                res.push_back(i);
                unSet[i] -= 1;
            }
        }
        return res;
    }
};