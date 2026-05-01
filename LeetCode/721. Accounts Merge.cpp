// 这道题其实是标准并查集求解，不过一开始卡壳了没想到

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    // 并查集核心：查找根节点
    string find(unordered_map<string, string>& parent, string x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_to_name; // 邮箱→用户名
        unordered_map<string, string> parent;        // 并查集：邮箱→父邮箱

        // 1. 初始化并查集 + 映射用户名
        for (auto& ac : accounts) {
            string name = ac[0];
            for (int i = 1; i < ac.size(); ++i) {
                string email = ac[i];
                email_to_name[email] = name;
                parent[email] = email; // 自己是自己的父节点
            }
        }

        // 2. 合并同一个账户的所有邮箱
        for (auto& ac : accounts) {
            string first_email = ac[1];
            for (int i = 2; i < ac.size(); ++i) {
                // 把当前邮箱 合并到 第一个邮箱的集合中
                parent[find(parent, ac[i])] = find(parent, first_email);
            }
        }

        // 3. 按根邮箱分组
        unordered_map<string, vector<string>> groups;
        for (auto& p : email_to_name) {
            string email = p.first;
            string root = find(parent, email);
            groups[root].push_back(email);
        }

        // 4. 排序 + 格式化输出
        vector<vector<string>> res;
        for (auto& p : groups) {
            auto& emails = p.second;
            sort(emails.begin(), emails.end());
            // 开头插入用户名
            emails.insert(emails.begin(), email_to_name[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};