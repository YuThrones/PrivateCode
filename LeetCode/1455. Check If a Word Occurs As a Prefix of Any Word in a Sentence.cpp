class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        int i = 0;
        while(i < sentence.length()) {
            int j = 0;
            while(j < searchWord.length()) {
                // cout << i << j << endl;
                if (i + j >= sentence.length() || sentence[i + j] != searchWord[j]) {
                    break;
                }
                ++j;
            }
            if (j == searchWord.length()) {
                return index;
            }
            ++index;
            while(i < sentence.length() && sentence[i] != ' ') {
                ++i;
            }
            ++i;
        }
        return -1;
    }
};