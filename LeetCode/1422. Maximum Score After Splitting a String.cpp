class Solution {
public:
    int maxScore(string s) {
        int total0 = 0;
        int total1 = 0;
        for (auto c : s) {
            if (c == '0') {
                ++total0;
            }
            else {
                ++total1;
            }
        }
        int score = 0;
        int num0 = 0;
        int num1 = 0;
        for (auto c : s) {
            if (c == '0') {
                ++num0;
            }
            else {
                ++num1;
            }
            if ((num0 + num1 > 0) && (num0 + num1 < total0 + total1)) {
                score = max(score, num0 + (total1 - num1));
            }
        }
        return score;
    }
};