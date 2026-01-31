// 本质是转化成最长公共子序列问题

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < n2; ++j) {
                int temp = 0;
                if (i > 0) {
                    temp = max(temp, dp[i - 1][j]);
                }
                if (j > 0) {
                    temp = max(temp, dp[i][j - 1]);
                }
                if (word1[i] == word2[j]) {
                    if (i > 0 && j > 0) {
                        temp = max(temp, dp[i - 1][j - 1] + 1);
                    }
                    else {
                        temp = max(temp, 1);
                    }
                }
                dp[i][j] = temp;
                // cout << i << " " << j << " " << temp << endl;
            }
        }
    
        return n1 + n2 - 2 * dp[n1 - 1][n2 - 1];
    }
};