// 最佳答案用int替换string，比我傻傻用string转换快多了

#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <vector>
#include <string>

using namespace std;

// Fast I/O
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        auto parse = [](const string& s) {
            return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        };
        
        int t = parse(target);
        bool visited[10000] = {false};
        
        for (const string& s : deadends) {
            visited[parse(s)] = true;
        }
        
        if (visited[0] || visited[t]) return -1;
        if (t == 0) return 0;
        
        int q[10000];
        int head = 0, tail = 0;
        
        q[tail++] = 0;
        visited[0] = true;
        
        int dist = 1;
        int pow10[4] = {1, 10, 100, 1000};
        
        while (head < tail) {
            int sz = tail - head;
            for (int i = 0; i < sz; ++i) {
                int cur = q[head++];
                
                for (int p10 : pow10) {
                    int digit = (cur / p10) % 10;
                    
                    int up = cur + (digit == 9 ? -9 * p10 : p10);
                    if (up == t) return dist; 
                    if (!visited[up]) {
                        visited[up] = true;
                        q[tail++] = up;
                    }
                    
                    int down = cur + (digit == 0 ? 9 * p10 : -p10);
                    if (down == t) return dist;
                    if (!visited[down]) {
                        visited[down] = true;
                        q[tail++] = down;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto& d :deadends) {
            dead.insert(d);
        }
        if (dead.contains("0000")) {return -1;}
        dead.insert("0000");
        vector<string> queue;
        queue.push_back("0000");
        int cnt = 0;
        while(!queue.empty()) {
            vector<string> temp;
            for(auto& s : queue) {
                if (s == target) {
                    return cnt;
                }
                for(int i = 0; i < 4; ++i) {
                    string temp_s = s;
                    int num = s[i] - '0';
                    temp_s[i] = (num + 10 + 1) % 10 + '0';
                    if (!dead.contains(temp_s)) {
                        temp.push_back(temp_s);
                        dead.insert(temp_s);
                    }
                    temp_s[i] = (num + 10 - 1) % 10 + '0';
                    if (!dead.contains(temp_s)) {
                        temp.push_back(temp_s);
                        dead.insert(temp_s);
                    }
                }
            }
            queue = move(temp);
            ++cnt;
        }
        return -1;
    }
};