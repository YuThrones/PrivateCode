// 没什么好说的，遍历一遍，用vector记录下出现过的数字，其他的收集起来返回就行

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> temp(nums.size() + 1, 0);
        for (auto &n: nums) {
            temp[n] = 1;
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (!temp[i]) res.push_back(i);
        }
        return res;
    }
};