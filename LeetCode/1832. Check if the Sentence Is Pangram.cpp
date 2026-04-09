class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> rec(26, 0);
        for (auto c : sentence) {
            rec[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (rec[i] == 0) {
                return false;
            }
        }
        return true;
    }
};