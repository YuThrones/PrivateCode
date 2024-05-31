// 先用宽度优先遍历练习，后面再试试动态规划

#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
    unordered_set<string> visited;
    vector<vector<string>> graph;

    Solution() {
        for (int i = 0; i < 26; ++i) {
            graph.push_back(vector<string>());
        }
    }

    int minStickers(vector<string>& stickers, string target) {
        sort(target.begin(), target.end());
        graph.clear();
        visited.clear();
        
        for (int i = 0; i < 26; ++i) {
            graph.push_back(vector<string>());
        }

        queue<string> que;

        for (auto& s: stickers) {
            sort(s.begin(), s.end());
            for (int i = 0; i < s.length(); ++i) {
                if (i == 0 || s[i] != s[i - 1]) {
                    graph[s[i] - 'a'].push_back(s);
                }
            }
        }

        que.push(target);
        int level = 1;
        visited.insert(target);
        int size = 1;
        int nextSize = 0;
        while(size) {
            string ft = que.front();
            que.pop();
            --size;
            for (int i = 0; i < ft.length(); ++i) {
                if (i == 0 || ft[i] != ft[i - 1]) {
                    for (auto& ss: graph[ft[i] - 'a']) {
                        string nxt = getNext(ss, ft);
                        if (visited.find(nxt) != visited.end()) continue;
                        if (nxt == "") {
                            return level;
                        }
                        ++nextSize;
                        visited.insert(nxt);
                        que.push(nxt);
                    }
                }
            }
            if (size == 0) {
                size = nextSize;
                nextSize = 0;
                ++level;
            }
        }

        return -1;
    }

    string getNext(string st, string target) {
        int i = 0, j = 0;
        string ans;
        ans.reserve(target.length());
        while(j < target.length()) {
            if (i == st.length() || st[i] > target[j]) {
                ans += (target[j++]);
            }
            else if (st[i] < target[j]) {
                ++i;
            }
            else {
                ++i;
                ++j;
            }
        }
        return ans;
    }
};

int main() {
    cout << " start" << endl;
    Solution sol;
    vector<string> stickers{"with","example","science"};
    string target = "thehat";
    sol.minStickers(stickers, target);
    cout << " end" << endl;
    return 0;
}
