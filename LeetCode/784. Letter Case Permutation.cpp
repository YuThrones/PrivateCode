class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans{""};
        for(int i = 0; i < s.length(); ++i) {
            vector<string> tsv;
            for(string& a : ans) {
                char c = s[i];
                if (c >= 'a' && c <= 'z') {
                    tsv.push_back(a + c);
                    tsv.push_back(a + char(c - 'a' + 'A'));
                }
                else if(c >= 'A' && c <= 'Z') {
                        tsv.push_back(a + c);
                        tsv.push_back(a + char(c - 'A' + 'a'));
                    }
                else {
                    tsv.push_back(a + c);
                }
            }
            ans = move(tsv);
        }
        return ans;
    }
};