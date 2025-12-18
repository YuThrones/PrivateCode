// 想复杂了，还在一位一位比较，最佳答案直接整个查找，找到长度就多1，代码优雅多了

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated = word;
        while(sequence.find(repeated) != string::npos){
            k++;
            repeated+=word;
        }
        return k;
    }
};

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        int i = 0;
        int n = word.length();
        int m = sequence.length();
        while(i < m) {
            if (i + n > m) {
                break;
            }
            for (int j = 0; j < m / n + 1; ++j) {
                bool dif = false;
                for (int k = 0; k < n; ++k) {
                    if (sequence[i + j * n + k] != word[k]) {
                        dif = true;
                        ++i;
                        break;
                    }
                }
                if (dif) {
                    ans = max(ans, j);
                    break;
                }
            }
        }
        return ans;
    }
};