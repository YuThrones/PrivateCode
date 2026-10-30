// 这道题挺简单的，贪心就完了，排个序，然后从前面尽可能拿分，拿不了分就去后面用分数买尽可能大的token，然后继续买分

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int ans = 0;
        sort(tokens.begin(), tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        while(start <= end) {
            if (power >= tokens[start]) {
                score++;
                power -= tokens[start];
                ++start;
                ans = max(ans, score);
            }
            else if (score > 0) {
                score--;
                power += tokens[end];
                --end;
            }
            else {
                break;
            }
        }
        return ans;
    }
};