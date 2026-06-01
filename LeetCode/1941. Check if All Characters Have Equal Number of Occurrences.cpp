class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> count(26, 0);
        int maxNum = 0;
        for(auto c : s) {
            count[c - 'a']++;
            maxNum = max(maxNum, count[c - 'a']);
        }
        for(int i = 0; i < 26; ++i) {
            if (count[i] > 0 && count[i] != maxNum) {
                return false;
            }
        }
        return true;
    }
};