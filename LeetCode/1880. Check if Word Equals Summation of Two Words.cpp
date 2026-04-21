class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getNum(firstWord) + getNum(secondWord) == getNum(targetWord);
    }

    int getNum(string& s) {
        int ans = 0;
        for(auto c : s) {
            ans = ans * 10 + c - 'a';
        }
        return ans;
    }
};