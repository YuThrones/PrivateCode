// 跟上道题事实上是一样的，只是不是记录是否存在，而是需要计算出所有的答案，用一个vector收集答案即可
// 最佳答案是用前缀树解的，在大量前缀重复时可能比较会快一点
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string> > dp = vector<vector<string> >();
        for (int i = 0; i < s.length(); ++i) {
            dp.push_back(vector<string>());
            for (int j = 0; j < wordDict.size(); ++j) {
                string temp = wordDict[j];
                int length = temp.length();
                int start = i - (length - 1);
                if (start == 0) {
                    if (s.compare(start, length, temp) == 0) {
                        dp[i].push_back(temp);
                    }
                }
                else if (start > 0 && dp[start-1].size() > 0) {
                    if (s.compare(start, length, temp) == 0) {
                        for (int k = 0; k < dp[start-1].size(); ++k) {
                            dp[i].push_back(dp[start-1][k] + " " + temp);
                        }    
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
};