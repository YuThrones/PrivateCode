// 解法很容易想到，最佳答案快关键在于样本量小，直接预处理了，实际只需要查表，没有每次计算

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> rec;
        queue<string> que;
        string cur = "";
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 3; ++j) {
                cur += to_string(board[i][j]);
            }
        }
        rec[cur] = 0;
        que.push(cur);
        while(!que.empty()) {
            string front = que.front();
            que.pop();
            if (front == "123450") {
                return rec[front];
            }
            for(int i = 0; i < 6; ++i) {
                if (front[i] != '0') {
                    continue;
                }
                if (i - 3 >= 0) {
                    string temp = front;
                    temp[i - 3] = front[i];
                    temp[i] = front[i - 3];
                    if (rec.find(temp) == rec.end()) {
                        rec[temp] = rec[front] + 1;
                        que.push(temp);
                    }
                }
                if (i + 3 < 6) {
                    string temp = front;
                    temp[i + 3] = front[i];
                    temp[i] = front[i + 3];
                    if (rec.find(temp) == rec.end()) {
                        rec[temp] = rec[front] + 1;
                        que.push(temp);
                    }
                }
                if (i == 1 || i == 2 || i == 4 || i == 5) {
                    string temp = front;
                    temp[i - 1] = front[i];
                    temp[i] = front[i - 1];
                    if (rec.find(temp) == rec.end()) {
                        rec[temp] = rec[front] + 1;
                        que.push(temp);
                    }
                }
                if (i == 0 || i == 1 || i == 3 || i == 4) {
                    string temp = front;
                    temp[i + 1] = front[i];
                    temp[i] = front[i + 1];
                    if (rec.find(temp) == rec.end()) {
                        rec[temp] = rec[front] + 1;
                        que.push(temp);
                    }
                }
            }
        }
        return -1;
    }
};

// 最佳答案

class Solution {
public:
    inline static unordered_map<string, int> moves;
    inline static string states[360];
    inline static vector<vector<int>> adj = 
        { {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4} };

    inline static bool init = []() {
        moves["123450"] = 0;
        states[0] = "123450";
        size_t n = 1;

        for (size_t i = 0; i < n; i++) {
            string s = states[i];
            size_t z = s.find('0');

            for (int a : adj[z]) {
                string S = s;
                swap(S[z], S[a]);

                if (!moves.count(S)) {
                    moves[S] = moves[s] + 1;
                    states[n++] = S;
                }
            }
        }
        return 0;
    }();

    int slidingPuzzle(vector<vector<int>>& b) {
        string s = "";
        for (auto& r : b)
            for (auto& c : r)
                s += to_string(c);

        return moves.count(s) ? moves[s] : -1;
    }
};