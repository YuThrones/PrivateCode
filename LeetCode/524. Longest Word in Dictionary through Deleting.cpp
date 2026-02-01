class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (auto& w : dictionary) {
            if (isFront(ans, w)) {
                continue;
            }
            if (isSub(s, w)) {
                ans = w;
            }
        }
        return ans;
    }

    bool isSub(string& s, string& w) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < w.length()) {
            if (s[i] == w[j]) {
                ++i;
                ++j;
            }
            else {
                ++i;
            }
        }
        return j == w.length();
    }

    bool isFront(string& a, string& b) {
        if (a.length() > b.length()) {
            return true;
        }
        if (a.length() < b.length()) {
            return false;
        }
        for(int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i]) {
                continue;
            }
            return a[i] < b[i];
        }
        return true;
    }
};