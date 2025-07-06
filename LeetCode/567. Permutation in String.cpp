class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if (n > s2.size()) {
            return false;
        }
        if (n == 0) {
            return true;
        }

        vector<int> require(26, 0);
        vector<int> count(26, 0);

        int need_num = 0;
        for (auto c :s1) {
            if (++require[c - 'a'] == 1) {
                ++need_num;
            }
        }

        int i = 0;
        int right_num = 0;
        for (; i < n; ++i) {
            auto c = s2[i];
            int index = c - 'a';
            if (++count[index] == require[index]) {
                ++right_num;
            }
        }

        if (right_num == need_num) {
            return true;
        }

        for (; i < s2.size(); ++i) {
            if (--count[s2[i - n] - 'a'] == require[s2[i - n] - 'a'] - 1) {
                --right_num;
            }
            auto c = s2[i];
            int index = c - 'a';
            if (++count[index] == require[index]) {
                ++right_num;
            }

            if (right_num == need_num) {
                return true;
            }
        }
        return false;
    }
};