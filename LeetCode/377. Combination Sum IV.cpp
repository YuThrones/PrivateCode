// 这道题我的思路是先用动态规划算出去重的答案，再用排列组合的计算重复的答案
// 看了下最快答案，事实上我脑子秀逗想复杂了，几行代码就解决的问题，事实上暴力深度搜索加上记忆化存储就搞定了

#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<vector<vector<int>>>> dp;
        for (int i = 0; i <= target; ++i) {
            dp.push_back(vector<vector<vector<int>>>());
            for (int j = 0; j < nums.size(); ++j) {
                dp[i].push_back(vector<vector<int>>());
            }
        }
        cal(nums, target, 0, dp);


        // for (int i = 0; i <= target; ++i) {
        //     for (int j = 0; j < nums.size(); ++j) {
        //         cout << "target: " << i << " start: " << j << endl;
        //         for (auto sub : dp[i][j]) {
        //             for (auto n: sub) {
        //                 cout << n << " ";
        //             }
        //             cout << endl;
        //         }
        //     }
        // }

        // 这里拿到去重的答案，算一下不同数字的排列组合
        vector<vector<int>> uniqueRes = dp[target][0];
        int res = 0;
        for (vector<int> row: uniqueRes) {
            sort(row.begin(), row.end());

            int total = accumulate(row.begin(), row.end(), 0);
            int temp = 1;

            for (int col: row) {
                temp *= calC(total, col);
                total -= col;
            }

            res += temp;
        }
        return res;
    }

    int calC(int total, int choose) {
        int ans = 1;
        if (choose > total / 2) {
            choose = total - choose;
        }
        for (int i = 0; i < choose; ++i) {
            ans *= (total - i);
            ans /= (1 + i);
        }
        return ans;
    }
    
    vector<vector<int>> cal(vector<int>& nums, int target, int start, vector<vector<vector<vector<int>>>>& dp) {
        vector<vector<int>> res;
        if (start >= nums.size()) return res;
        if (target <= 0) return res;
        if (nums[start] > target) return res;
        
        if (dp[target][start].size() > 0) {
            return dp[target][start];
        }

        int n = nums[start];
        for (int i = 0; i * n <= target; ++i) {
            if (i * n == target) {
                vector<int> temp;
                temp.push_back(i);
                res.push_back(temp);
            }
            else {
                vector<vector<int>> sub = cal(nums, target - i * n, start + 1, dp);
                for (vector<int> sv: sub) {
                    if (sv.empty()) {
                        continue;
                    }
                    vector<int> temp;
                    temp.push_back(i);
                    temp.insert(temp.end(), sv.begin(), sv.end());
                    res.push_back(temp);
                }

            }
        }

        if (res.empty()) res.push_back(vector<int>());
        dp[target][start] = res;
        return res;
    }
};


int main() {
    Solution sol;
    // vector<int> nums{1, 2, 3};
    // int target = 4;
    // vector<int> nums{5, 1, 8};
    // int target = 24;
    // vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    // int target = 31;

    vector<int> nums{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target = 999;
    sol.combinationSum4(nums, target);
    // int total = 24;
    // for (int i = 0; i <= total; ++i) {
    //     cout << sol.calC(total, i) << endl;

    // }
    return 0;
}