// 位置相同的收集，不同的记录数量，然后取较小值即可

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int count1[10]{0};
        int count2[10]{0};
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                continue;
            }
            ++count1[secret[i] - '0'];
            ++count2[guess[i] - '0'];
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(count1[i], count2[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};