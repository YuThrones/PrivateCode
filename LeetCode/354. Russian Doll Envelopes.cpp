// 这道题的思路是把问题转换为求最长递增子序列的问题，因为不熟悉lower_bound的设计，卡了很久
// 最快答案思路完全一致，但是常数时间上优势很大，需要再分析下，推测是因为vector的排序可能涉及到vector的复制

#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 这样排序之后，可以转换为找最长递增子序列的问题
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> numbers;

        for (auto v: envelopes) {
            numbers.push_back(v[1]);
        }

        vector<int> dp(numbers.size() + 1, INT_MAX);
        dp[0] = 0;

        int res = 0;
        for (int i = 0; i < numbers.size(); i++) {
            auto iter = lower_bound(dp.begin(), dp.begin() + res + 1, numbers[i]);
            int index = iter - dp.begin() - 1;


            if (dp[index] < numbers[i]) {
                dp[index + 1] = min(dp[index + 1], numbers[i]);
                res = max(res, index + 1);
            }
            else {
                break;
            }

            
        }

        return res;
    }

};

int main() {
    Solution solution;
    // vector<vector<int>> envelopes{{{33,23},{43,3},{10,43}}};
    // vector<int> test{10, 20, 30, 40, 50};

    // auto i = upper_bound(test.begin(), test.end(), 19, greater<int>());

    // cout << i - test.begin() << " " << *i << endl;

    // cout << upper_bound(test.begin(), test.end(), 0, greater<int>()) - test.begin() << endl;
    // cout << upper_bound(test.begin(), test.end(), 10, greater<int>()) - test.begin() << endl;
    // cout << upper_bound(test.begin(), test.end(), 20, greater<int>()) - test.begin() << endl;
    // cout << upper_bound(test.begin(), test.end(), 50, greater<int>()) - test.begin() << endl;
    // cout << upper_bound(test.begin(), test.end(), 60, greater<int>()) - test.begin() << endl;

    // vector<vector<int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
    // vector<vector<int>> envelopes{{4,5},{4,6},{6,7},{2,3},{1,1}};
    // vector<vector<int>> envelopes{{1,2},{2,3},{3,4},{3,5},{4,5},{5,5},{5,6},{6,7},{7,8}};
    vector<vector<int>> envelopes{{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
    cout << solution.maxEnvelopes(envelopes) << endl;
    return 0;
}