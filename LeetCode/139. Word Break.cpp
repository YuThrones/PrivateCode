// 直接深度优先搜索，加上记忆就可以解决，可以再把这个改成动态规划的形式，如下面wordBreak2

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> record = unordered_map<int, bool>();
        return process(s, wordDict, 0, record);
    }
    
    bool process(string s, vector<string>& wordDict, int start, unordered_map<int, bool>& record) {
        if (record.find(start) != record.end())
        {
            return record[start];
        }
        
        if (start > s.length() - 1)
        {
            return true;
        }
        
        for (int i = 0; i < wordDict.size(); ++i)
        {
            if (s.compare(start, wordDict[i].length(), wordDict[i]) == 0)
            {
                if (process(s, wordDict, start + wordDict[i].length(), record))
                {
                    return true;
                }
            }
        }
        record[start] = false;
        return false;
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<bool> dp = vector<bool>();
        for (int i = 0; i < s.length(); ++i)
        {
            dp.push_back(false);
        }
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < wordDict.size(); ++j)
            {
                string temp = wordDict[j];
                int length = temp.length();
                int start = i - (length - 1);
                if (start == 0 || (start > 0 && dp[start-1]))
                {
                    if (s.compare(start, length, temp) == 0)
                    {
                        dp[i] = true;
                    }
                }
            }
            
        }
        return dp[s.length() - 1];
    }
};

int main()
{
    // string a = "aaaaaaab";
    // vector<string> vs;
    // vs.push_back("a");
    // vs.push_back("aa");
    // vs.push_back("aaa");
    // vs.push_back("aaaa");
    string a = "leetcode";
    vector<string> vs;
    vs.push_back("leet");
    vs.push_back("code");
    Solution s = Solution();
    cout << s.wordBreak2(a, vs);
}