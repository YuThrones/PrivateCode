// 也是经典前缀树应用场景，需要注意的是找到一个答案之后，需要把一个词从树里面去掉，避免循环查找
// 看了下最佳答案，思路是一样的，copy跑了下甚至没跑过，可能用例变了

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Trie {
public:
    bool flag = false;
    Trie* next[26];
    int count = 0;
};

class Solution {
public:
    Trie* root;
    vector<vector<int>> dir;
    
    void initTrie(vector<string>& words) {
        root = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            addWord(words[i]);
        }
        for (int i = 0; i < 4; ++i) {
            dir.push_back(vector<int>());
        }
        dir[0].push_back(-1);
        dir[0].push_back(0);
        dir[1].push_back(1);
        dir[1].push_back(0);
        dir[2].push_back(0);
        dir[2].push_back(-1);
        dir[3].push_back(0);
        dir[3].push_back(1);
    }
    
    void addWord(string& word) {
        Trie* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!cur->next[index]) {
                cur->next[index] = new Trie();
                cur->count += 1;
            }
            cur = cur->next[index];
        }
        cur->flag = true;
    }

    void removeWord(string& word) {
        Trie* cur = root;
        stack<Trie*> st1;
        stack<int> st2;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!cur->next[index]) {
                return;
            }
            st1.push(cur);
            st2.push(index);
            cur = cur->next[index];
        }

        if (!cur->flag) {
            return;
        }

        cur->flag = false;

        while(!st1.empty()) {
            if (!cur->count) {
                st1.top()->count -= 1;
                st1.top()->next[st2.top()] = nullptr;
            }
            cur = st1.top();
            st1.pop();
            st2.pop();
        }
    }
    
    
    vector<string> findWord(vector<vector<char>>& board, Trie* cur, vector<vector<bool>>& visited, int row, int col) {
        vector<string> res;
        if (visited[row][col]) {
            return res;
        }
        
        char c = board[row][col];
        if (!cur->next[c - 'a']) {
            return res;
        }
        
        visited[row][col] = true;
        Trie* next = cur->next[c - 'a'];
        if (next->flag) {
            res.push_back(string(1, c));
        }
        
        for (auto d: dir) {
            int next_row = row + d[0];
            int next_col = col + d[1];
            if (next_row < 0 
                || next_row > visited.size() - 1
                || next_col < 0 
                || next_col > visited[0].size() - 1) {
                continue;
            }
            vector<string> next_res = findWord(board, next, visited, next_row, next_col);
            for (auto s: next_res) {
                res.push_back(string(1, c) + s);
            }
        }
        
        visited[row][col] = false;
        
        return res;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        initTrie(words);
        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); ++i) {
            visited.push_back(vector<bool>());
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i].push_back(false);
            }
        }
        vector<string> res;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                vector<string> temp = findWord(board, root, visited, i, j);
                for (auto s: temp) {
                    res.push_back(s);
                    removeWord(s);
                }
            }
        }
        
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};


int main() {
    vector<vector<char>> board;
    board.push_back(vector<char>());
    board.push_back(vector<char>());
    board.push_back(vector<char>());
    board.push_back(vector<char>());
    board[0].push_back('o');
    board[0].push_back('a');
    board[0].push_back('a');
    board[0].push_back('n');
    board[1].push_back('e');
    board[1].push_back('t');
    board[1].push_back('a');
    board[1].push_back('e');
    board[2].push_back('i');
    board[2].push_back('h');
    board[2].push_back('k');
    board[2].push_back('r');
    board[3].push_back('i');
    board[3].push_back('f');
    board[3].push_back('l');
    board[3].push_back('v');

    vector<string> words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");

    Solution s = Solution();
    vector<string> res = s.findWords(board, words);
    for (auto r : res) {
        cout << r << endl;
    }

    string ss = "eat";
    s.removeWord(ss);
    return 0;
}