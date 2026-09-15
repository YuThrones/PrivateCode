class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto& w : words) {
            vector<int> rec1(26, -1);
            vector<int> rec2(26, -1);
            if(w.length() != pattern.length()) {
                continue;
            }
            int n = w.length();
            bool ok = true;
            for(int i = 0; i < n; ++i) {
                int a = w[i] - 'a';
                int b = pattern[i] - 'a';
                if (rec1[a] == b && rec2[b] == a) {
                    continue;
                }
                if (rec1[a] == -1 && rec2[b] == -1) {
                    rec1[a] = b;
                    rec2[b] = a;
                    continue;
                }
                ok = false;
                break;
            }
            if(ok) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};