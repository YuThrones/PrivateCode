class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        if (s.length() == 0) {return result;}
        char last = s[0];
        int start = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != last) {
                if (i - start >= 3) {
                    result.push_back(vector<int> {start, i - 1});
                }
                last = s[i];
                start = i;
            }
        }
        if (s.length() - start >= 3) {
            result.push_back(vector<int> {start, (int)s.length() - 1});
        }
        return result;
    }
};