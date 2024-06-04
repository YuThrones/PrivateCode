#include<string>
#include<memory.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string s1, s2;
        s1 = text1.length() < text2.length() ? text1 : text2;
        s2 = text1.length() < text2.length() ? text2 : text1;

        int dp[s1.length() + 1];
        memset(dp, 0, sizeof(dp));
        int leftup = 0, backup = 0;

        for (int i = 1; i <= s2.length(); ++i) {
            leftup = backup = 0;
            for (int j = 1; j <= s1.length(); ++j) {
                backup = dp[j];
                if (s2[i - 1] == s1[j - 1]) {
                    dp[j] = leftup + 1;
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                leftup = backup;
            }
        }


        return dp[s1.length()];
    }
};

int main() {
    Solution sol;
    string text1 = "bsbininm";
    string text2 = "jmjkbkjkv";
    sol.longestCommonSubsequence(text1, text2);
    return 0;
}

// class Solution {
//     int dp[1001][1001];
//     int helper(string &S1, string &S2, int n, int m)
//     {
        
//         if(n == 0 || m == 0)
//         {
//             dp[n][m] = 0;
//             return 0;
//         }
        
//         if(dp[n][m] != -1) return dp[n][m];
        
//         if(S1[n - 1] == S2[m - 1])
//         {
//             return dp[n][m] = ( 1 + helper(S1, S2, n - 1, m - 1) );
//         }

//         return dp[n][m] = max( helper(S1, S2, n - 1, m), helper(S1, S2, n, m - 1) );

//     }
//     public:
//     int longestCommonSubsequence(string S1, string S2) 
//     {
//         int n = S1.length();
//         int m = S2.length();
//         memset(dp, -1, sizeof(dp));
//         return helper(S1, S2, n, m);        
        
            
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {
        if ( X.size() < Y.size() ) swap(X,Y) ;
        int m = X.size() , n = Y.size();
        if (m == 0 || n == 0) return 0;
        int w = (m + 31) >> 5;
        std::uint32_t S[256][w];
        std::memset(S, 0, sizeof(std::uint32_t) * 256 * w);
        std::int32_t set = 1;
        for (int i = 0, j = 0; i < m; ++i) {
            S[X[i]][j] |= set;
            set <<= 1;
            if (!set) set++,j++;
        }
        std::uint32_t L[w];
        std::memset(L, 0, sizeof(std::uint32_t) * w);
        for (int i = 0; i < n; ++i) {
            std::uint32_t b1 = 1;
            std::uint32_t b2 = 0;
            for (int j = 0; j < w; ++j) {
                std::uint32_t U  = L[j] | S[Y[i]][j];
                std::uint32_t c  = L[j] >> 31;
                std::uint32_t V  = U - (L[j] << 1 | b1+b2);
                b1 = c;
                b2 = (V > U);
                L[j] = U & (~V);
            }
        }      
        int res = 0;
        for (int i = 0; i < w; ++i)
            for (; L[i]; ++res)
                L[i] &= L[i] - 1;
        return res;
    }
};