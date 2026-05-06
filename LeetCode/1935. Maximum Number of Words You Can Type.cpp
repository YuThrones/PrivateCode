class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        int start = 0;
        for(int i = 0; i <= text.length(); ++i) {
            if (i == text.length() || text[i] == ' ') {
                string s = text.substr(start, i - start);
                bool ok = true;
                for(int j = 0; j < brokenLetters.length(); ++j) {
                    if (s.contains(brokenLetters[j])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ++ans;
                }
                start = i + 1;
            }
        }
        return ans;
    }
};