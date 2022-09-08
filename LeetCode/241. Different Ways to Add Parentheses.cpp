// 递归加缓存就可以得出动态规划的解

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> number;
        vector<char> op;
        
        string temp = "";
        
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                op.push_back(c);
                if (temp.length() > 0) {
                    number.push_back(stoi(temp));
                }
                temp = "";
            }
            else {
                temp += c;
            }
        }
        number.push_back(stoi(temp));

        vector<vector<vector<int>> > dp(number.size());
        for (int i = 0; i < number.size(); ++i) {
            dp[i] = vector<vector<int>>(number.size());
        }
        return handle(number, op, 0, number.size() - 1, dp);
    }
    
    vector<int> handle(vector<int>& number, vector<char>& op, int start, int end, vector<vector<vector<int>> >& dp) {
        if (dp[start][end].size() > 0) {
            return dp[start][end];
        }

        vector<int> res;
        if (start >= end) {
            res.push_back(number[start]);
            dp[start][end] = res;
            return res;
        }

        vector<int> subRes1;
        vector<int> subRes2;

        for (int i = start; i < end; ++i) {
            subRes1 = handle(number, op, start, i, dp);
            subRes2 = handle(number, op, i + 1, end, dp);
            for (auto sr1: subRes1) {
                for (auto sr2: subRes2) {
                    if (op[i] == '+') {
                        res.push_back(sr1 + sr2);
                    }
                    else if (op[i] == '-') {
                        res.push_back(sr1 - sr2);
                    }
                    else if (op[i] == '*') {
                        res.push_back(sr1 * sr2);
                    }
                    else if (op[i] == '/') {
                        res.push_back(sr1 / sr2);
                    }
                }
            }
        }

        dp[start][end] = res;
        return res;
    }

    vector<int> handle2(string expression) {
        vector<int> number;
        vector<char> op;
        
        string temp = "";
        
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                op.push_back(c);
                if (temp.length() > 0) {
                    number.push_back(stoi(temp));
                }
                temp = "";
            }
            else {
                temp += c;
            }
        }
        number.push_back(stoi(temp));

        vector<vector<vector<int>> > dp(number.size());
        for (int i = 0; i < number.size(); ++i) {
            dp[i] = vector<vector<int>>(number.size());
            // for (int j = 0; j < number.size(); ++j) {
            //     dp[i][j].push_back(0);
            // }
        }

        for (int i = 0; i < number.size(); ++i) {
            // 初始化对角线
            dp[i][i].push_back(number[i]);
        }

        vector<int> subRes1;
        vector<int> subRes2;

        for (int start = number.size() - 2; start >= 0; --start) {
            // 从右下角往左上角的对角线开始，往右遍历处理整行
            for (int end = start + 1; end < number.size(); ++end) {
                for (int i = start; i < end; ++i) {
                    subRes1 = dp[start][i];
                    subRes2 = dp[i + 1][end];
                    // vector<int> res = dp[start][end];
                    for (auto sr1: subRes1) {
                        for (auto sr2: subRes2) {
                            if (op[i] == '+') {
                                dp[start][end].push_back(sr1 + sr2);
                            }
                            else if (op[i] == '-') {
                                dp[start][end].push_back(sr1 - sr2);
                            }
                            else if (op[i] == '*') {
                                dp[start][end].push_back(sr1 * sr2);
                            }
                            else if (op[i] == '/') {
                                dp[start][end].push_back(sr1 / sr2);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][number.size() - 1];
    }
};

int main() {
    Solution solution;
    vector<int> res = solution.handle2("2-1-1");

}