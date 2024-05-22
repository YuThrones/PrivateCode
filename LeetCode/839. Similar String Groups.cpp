// 这道题是非常经典的可以用并查集处理的题目，把相似的字符扔进一个集合合并，字符的相似用不同字母是否为0或2判断就行，非常高效
// 最快答案是用dfs来做，每次一个词找到他所有的相似词，并且置为空（这里很重要，相当于剪枝避免了重复搜索），直到这个词相似词都找完

#include<vector>
#include<string>
using namespace std;

#define MAIN_MAX 301

class Solution {
public:
    int father[MAIN_MAX];

    int numSimilarGroups(vector<string>& strs) {
        build(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                int diff = 0;
                for (int l = 0; l < strs[i].length() && diff < 3; ++l) {
                    if (strs[i][l] != strs[j][l]) {
                        ++diff;
                    }
                }
                if (diff == 0 || diff == 2) {
                    makeUnion(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < strs.size(); ++i) {
            if (i == father[i]) ++ans;
        }
        return ans;
    }

    void build(int n) {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    void makeUnion(int x, int y) {
        father[find(x)] = father[find(y)];
    }
};


class Solution {
private:
    bool checkSame(string &s, string &t) {
        int sz = size(s);
        int diff = 0;
        for(int i = 0; i < sz; ++i) {
            if(s[i] != t[i]) {
                ++diff;
            }
            if(diff > 2)
                return false;
        }
        
        return (diff <= 2);
    }
    
    void dfs(vector<string> &strs, string &check) {
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i] == "")
                continue;
            
            if(checkSame(strs[i], check)) {
                string temp = strs[i];
                strs[i] = "";
                dfs(strs, temp);
            }
            
        }
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(strs[i] == "")
                continue;
            
            string temp = strs[i];
            strs[i] = "";
            
            cnt++;
            dfs(strs, temp);
        }
        
        return cnt;
    }
};