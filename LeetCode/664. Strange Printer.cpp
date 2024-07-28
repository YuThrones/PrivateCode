// 动态规划可以解，把连续相同的部分压缩是一个不错的剪枝
// 最快答案是记录了每个位置相同的下一个数字的位置，然后以那个位置为分割点，本质上是一种剪枝


#include<string>
#include<vector>
#include<climits>
using namespace std;

const int inf = 1e5;

class Solution {
private:
    int chToI(char c) {
        return (int)(c - 'a');
    }

public:
    int strangePrinter(string s) {
        string compressed{};
        for (auto ch: s) {
            if (compressed.empty() || compressed.back() != ch) {
                compressed.push_back(ch);
            }
        }
        int len = compressed.size();
        vector<int> lst(30, len + 5);
        vector<int> nxt(len, -1);
        for (int i = len - 1; i >= 0; i--) {
            nxt[i] = lst[chToI(compressed[i])];
            lst[chToI(compressed[i])] = i;
        }
        vector<vector<int>> minT(len, vector<int>(len, inf));
        for (int curL = 0; curL < len; curL++) {
            for (int st = 0; st < len - curL; st++) {
                int en = st + curL;
                if (st == en) {
                    minT[st][en] = 1;
                    continue;
                }
                int &cost = minT[st][en];
                cost = 1 + minT[st + 1][en];
                int nxf = nxt[st];
                while (nxf <= en) {
                    cost = min(cost, minT[nxf][en] + minT[st + 1][nxf - 1]);
                    nxf = nxt[nxf];
                }
            }
        }
        return minT[0][len - 1] ;
    }
};

class Solution {
public:
    int strangePrinter(string s) {
        string compressed;
        for (auto c : s) {
            if (compressed.empty() || compressed.back() != c) {
                compressed.push_back(c);
            }
        }
        return strangePrinter1(s);
    }

    int strangePrinter1(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[n - 1][n - 1] = 1;
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1] ? 1 : 2);
        }

        for (int l = n - 3; l >= 0; --l) {
            for (int r = l + 2; r < n; ++r) {
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l][r - 1];
                }
                else {
                    int temp = INT_MAX;
                    for (int i = l; i < r; ++i) {
                        temp = min(temp, dp[l][i] + dp[i + 1][r]);
                    }
                    dp[l][r] = temp;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    string s = "aaabbb";
    int ans = sol.strangePrinter(s);
    return 0;
}