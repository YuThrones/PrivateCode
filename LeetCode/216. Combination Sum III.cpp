// 这道题要求数字唯一，所以用限定范围的方式递归即可，不需要动态规划

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return process(k, n, 1, 9);
    }
    
    vector<vector<int>> process(int k, int n, int start, int end) {
        vector<vector<int>> res;
        if (start > end) {
            return res;
        }
        
        if (k <= 0) {
            return res;
        }
        
        if (n <= 0) {
            return res;
        }

        
        vector<int> temp;
        
        if (k == 1 && n >= start && n <= end) {
            temp.push_back(n);
            res.push_back(temp);
            return res;
        }
        
        vector<vector<int>> sub_res;

        if (n > end) {
            sub_res = process(k - 1, n - end, start, end - 1);
            for (auto sub: sub_res) {
                sub.push_back(end);
                res.push_back(sub);
            }
        }
        
        
        sub_res = process(k, n, start, end - 1);
        for (auto sub: sub_res) {
            res.push_back(sub);
        }
        return res;
    }
};


int main() {
    Solution s = Solution();
    vector<vector<int>> res = s.combinationSum3(3, 7);
    return 0;
}