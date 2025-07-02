class Solution {
public:
    string sortString(string s) {
        vector<int> count(26, 0);
        for (auto c : s) {
            count[c - 'a']++;
        }
        string result;
        result.reserve(s.length());
        while(result.length() < s.length()) {
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    result.push_back(i + 'a');
                    --count[i];
                }
            }

            for (int i = 25; i >= 0; --i) {
                if (count[i] > 0) {
                    result.push_back(i + 'a');
                    --count[i];
                }
            }
        }
        return result;
    }
};