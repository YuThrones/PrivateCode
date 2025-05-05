class Solution {
    public:
        bool buddyStrings(string s, string goal) {
            if (s.length() != goal.length()) {
                return false;
            }
            int size = s.length();
            vector<int> record;
            for (int i = 0; i < size; ++i) {
                if (s[i] != goal[i]) {
                    record.push_back(i);
                    if (record.size() > 2) {
                        return false;
                    }
                }
            }
            if (record.size() == 0) {
                vector<int> count(27, 0);
                for (int i = 0; i < size; ++i) {
                    count[s[i] - 'a']++;
                    if (count[s[i] - 'a'] >= 2) {return true;}
                }
            }
            if (record.size() != 2) {
                return false;
            }
            return s[record[0]] == goal[record[1]] && s[record[1]] == goal[record[0]];
        }
    };