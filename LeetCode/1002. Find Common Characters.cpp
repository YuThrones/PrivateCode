class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, INT_MAX);
        for (auto w : words) {
            vector<int> temp(26, 0);
            for (auto  c: w) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                count[i] = min(count[i], temp[i]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            if (count[i] < INT_MAX) {
                for (int j = 0; j < count[i]; ++j) {
                    result.push_back(string(1, char(i + 'a')));
                }
            }
        }
        return result;
    }
};