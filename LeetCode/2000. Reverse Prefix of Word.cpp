class Solution {
public:
    string reversePrefix(string word, char ch) {

        int pos = word.find(ch);

        // không tìm thấy
        if (pos == string::npos) {
            return word;
        }

        // đảo prefix
        reverse(word.begin(), word.begin() + pos + 1);

        return word;
    }
};

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        for(int i = 0; i < word.length(); ++i) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        for(int i = 0; i < (index + 1) / 2; ++i) {
            char temp = word[i];
            word[i] = word[index - i];
            word[index - i] = temp;
        }
        return word;
    }
};