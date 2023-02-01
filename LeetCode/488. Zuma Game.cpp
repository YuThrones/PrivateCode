#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        map<char, int> hand_dict;
        // vector<int> count;
        for (auto c: hand) hand_dict[c] += 1;
        // for (int i = 0; i < board.size(); ++i) {
        //     count[i] += 1;
        // }
        
        // string new_board = merge(board);
        
        
        int ans = yu(board, hand_dict);
        if (ans == INT_MAX || ans == -1) return -1;
        return ans;
    }
    
    int yu(string board, map<char, int>& hand_dict) {
        if (board.length() == 0) return 0;
        if (hand_dict.size() == 0) return -1;
        
        int ans = INT_MAX;
        int length = board.length();
        for (int i = 0; i < length; ++i) {
            if (i == 0 || board[i] != board[i - 1]) {
                if (hand_dict.find(board[i]) != hand_dict.end()) {
                    hand_dict[board[i]] -= 1;
                    if (hand_dict[board[i]] <= 0) hand_dict.erase(board[i]);

                    int chr = board[i];
                    int extra = 1;
                    int left = i;
                    int right = i;
                    
                    // 这里要计算连环消除
                    int start = i;
                    int end = i;
                    while(left >= 0 && right < length) {
                        while((left >= 0) && (board[left] == chr)) --left;
                        while((right < length) && (board[right] == chr)) {
                            char temp = board[right];
                            ++right;
                        }
                        int cnt = right - left - 1 + extra;
                        extra = -cnt + 1;
                        if (cnt < 3) break;
                        else {
                            start = left + 1;
                            end = right - 1;
                        }
                        if (left >= 0) chr = board[left];
                        else if (right < length) chr = board[right];
                    }
                    
                    string sub;
                    if (end - start > 0) {
                        sub = board.substr(0, start) + board.substr(end + 1, length - end - 1);
                    }
                    else {
                        sub = board.substr(0, i + 1) + board[i] + board.substr(i + 1, length - 1 - i);
                    }
                    
                    // 分析从这个这个位置插入能否全部消除
                    
                    int sub_ans = yu(sub, hand_dict);
                    if (sub_ans != -1) {
                        ans = min(sub_ans + 1, ans);
                    }
                    
                    hand_dict[board[i]] += 1;
                }
            }
        }

        if (ans == INT_MAX) ans = -1;
        return ans;
    }
};


int main() {
    Solution solution;
    // cout << solution.merge("WRRBBBRW") << endl;
    // cout << solution.findMinStep("WRRBBW", "RB") << endl;
    cout << solution.findMinStep("RRWWRRBBRR", "WB") << endl;
    // cout << solution.findMinStep("WWRRBBWW", "WRBRW") << endl;
//     "WWRRBBWW"
// "WRBRW"
    return 0;
}