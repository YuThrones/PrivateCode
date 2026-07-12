// 普通从下往上填充思路不够快，最快解法是填一个格子立刻验证，减少可能性，自己没搞出来

class Solution {
    bool canBuild(int level, int index, int size,vector<string>& pyr, vector<vector<vector<char>>>& tri){
        if(index==0||index>=size) return true;
        for(char i : tri[pyr[level][index-1]][pyr[level][index]]) {
            pyr[level-1][index-1] = i;
            if(canBuild(level-1,index-1,index,pyr,tri)) if(canBuild(level,index+1,size,pyr,tri)) return true;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<char>>> tri(6,vector<vector<char>>(6));
        for(auto& t : allowed) tri[t[0]-'A'][t[1]-'A'].push_back(t[2]-'A');
        for(auto& c: bottom) c-='A';
        vector<string> pyr(bottom.size(),bottom);
        return canBuild(bottom.size()-1,1,bottom.size(),pyr,tri);
    }
};

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<string> memo; // 缓存无解的层，剪枝
    vector<char> rule[6][6];     // A-F映射0-5，二维规则表

    // 字符转0~5
    inline int idx(char c) { return c - 'A'; }

    bool dfs(const string& cur) {
        if (cur.size() <= 1) return true;
        if (memo.count(cur)) return false;

        vector<vector<char>> choices(cur.size() - 1);
        // 预处理每一对下层字符的可选上层字符
        for (int i = 0; i < cur.size() - 1; ++i) {
            int a = idx(cur[i]), b = idx(cur[i+1]);
            if (rule[a][b].empty()) { // 无合法转换，当前层无解
                memo.insert(cur);
                return false;
            }
            choices[i] = rule[a][b];
        }

        // 笛卡尔积生成所有上一层候选
        vector<string> floors{""};
        for (auto& opts : choices) {
            int sz = floors.size();
            vector<string> tmp;
            tmp.reserve(sz * opts.size()); // 预分配，避免多次扩容
            for (int i = 0; i < sz; ++i) {
                const string& s = floors[i];
                for (char c : opts) {
                    string ns = s;
                    ns.push_back(c);
                    tmp.emplace_back(ns);
                }
            }
            floors = move(tmp); // 移动语义，零拷贝转移容器
        }

        // 递归遍历所有上层，找到一条通路直接返回true
        for (const string& next : floors) {
            if (dfs(next)) return true;
        }
        memo.insert(cur);
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // 初始化规则表
        for (auto& s : allowed) {
            int x = idx(s[0]), y = idx(s[1]);
            rule[x][y].push_back(s[2]);
        }
        memo.clear();
        return dfs(bottom);
    }
};

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> rec;
        for(auto&s : allowed) {
            rec[s.substr(0, 2)].push_back(s[2]);
        }

        return isOk(bottom, rec);
    }

    bool isOk(string& bottom, unordered_map<string, vector<char>>& rec) {
        if (bottom.size() < 2) {
            return true;
        }

        vector<vector<char>> chance(bottom.size() - 1, vector<char>());
        for(int i = 0; i < bottom.size() - 1; ++i) {
            string temp = bottom.substr(i, 2);
            if (rec.find(temp) == rec.end()) {
                return false;
            }
            for(char c : rec[temp]) {
                chance[i].push_back(c);
            }
        }

        vector<string> future;
        future.push_back("");
        for(int k = 0; k < bottom.size() - 1; ++k) {
            int size = future.size();
            vector<string> temp;
            for(int i = 0; i < size; ++i) {
                for(int j = 0; j < chance[k].size(); ++j) {
                    string s = future[i];
                    s.push_back(chance[k][j]);
                    temp.emplace_back(s);
                }
            }
            future = move(temp);
        }

        for(string f : future) {
            if(isOk(f, rec)) {
                return true;
            }
        }

        return false;
    }
};