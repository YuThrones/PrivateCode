class Solution {
public:
    int firstUniqChar(string s) {
        int record[26];
        memset(record, 0, sizeof(record));
        for (auto c: s) {
            record[c - 'a'] += 1;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (record[s[i] - 'a'] < 2) {
                return i;
            }
        }
        return -1;
    }
};