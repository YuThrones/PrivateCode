class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<bool> record(26, false);
        for(char c :allowed) {
            record[c - 'a'] = true;
        }
        for(auto& w : words) {
            bool ok = true;
            for(auto c : w) {
                if(!record[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans++;
            }
        }
        return ans;
    }
};