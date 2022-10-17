// 这道题只要想清楚一个问题，记录下每个字母开头的最长不断的循环字符串的长度就行，之后只需要根据这个长度，把所有字母开头的最长长度加起来
// 就可以算出所有不重复的循环串的数量，最快答案也只是把vector换成了数组而已，没多大区别

#include<vector>
#include<unordered_map>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        int start = 0;
        int len;
        vector<int> dp(27, 0);
        for (int i = 1; i < p.length(); ++i) {
            if ((p[i] - p[i - 1] + 26) % 26 != 1) {
                for (int j = start; j < i; ++j) {
                    dp[p[j] - 'a'] = max(dp[p[j] - 'a'], i - j);
                }

                start = i;
            }
        }

        for (int j = start; j < p.length(); ++j) {
            dp[p[j] - 'a'] = max(dp[p[j] - 'a'], int(p.length()) - j);
        }

        for (int i = 0; i < dp.size(); ++i) {
            ans += dp[i];
        }

        return ans;
    }
};


int main() {
    // string str = "cac";
    string str = "zaba";
    Solution sol;
    sol.findSubstringInWraproundString(str);
    return 0;
}