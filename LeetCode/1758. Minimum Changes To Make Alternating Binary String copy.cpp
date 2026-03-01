class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string ans(word1.length() + word2.length(), '0');
        while(i < word1.length() && j < word2.length()) {
            ans[i + j] = word1[i];
            ++i;
            ans[i + j] = word2[j];
            ++j;
        }
        while(i < word1.length()) {
            ans[i + j] = word1[i];
            ++i;
        }
        while(j < word2.length()) {
            ans[i + j] = word2[j];
            ++j;
        }
        return ans;
    }
};