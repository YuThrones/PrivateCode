class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int lastR = -1;
        int lastL = -1;
        for(int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] == 'R') {
                if (lastR >= 0 && lastL <= lastR) {
                    for(int j = lastR + 1; j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
                lastR = i;
            }
            else if (dominoes[i] == 'L') {
                if (lastR > lastL) {
                    for(int j = 1; lastR + j < i - j; ++j) {
                        dominoes[lastR + j] = 'R';
                        dominoes[i - j] = 'L';
                    }
                }
                else {
                    for(int j = lastL + 1; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                }
                lastL = i;
            }
            else if (i == n - 1) {
                if (lastR > lastL) {
                    for(int j = lastR + 1; j <= i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
            }
        }
        return dominoes;
    }
};