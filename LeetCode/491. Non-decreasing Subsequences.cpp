// 这道题有点忘记要通过回溯的方式做了，想的剪枝思路太麻烦了，后面是看了答案做法

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        // 使用unordered_set对本层元素去重
        unordered_set<int> used_set; 
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used_set.find(nums[i]) != used_set.end()) {
                continue;
            }
            used_set.insert(nums[i]); // 记录本层已使用
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
            // used_set不需要pop，因为它是本层的局部变量
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};