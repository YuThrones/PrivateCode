class Solution {
    public:
        bool backspaceCompare(string s, string t) {
            vector<char> ns;
            vector<char> nt;
            for (auto c : s) {
                if (c == '#') {
                    if (!ns.empty()) {
                        ns.pop_back();
                    }
                }
                else {
                    ns.push_back(c);
                }
            }
             for (auto c : t) {
                if (c == '#') {
                    if (!nt.empty()) {
                        nt.pop_back();
                    }
                }
                else {
                    nt.push_back(c);
                }
            }
            if (ns.size() != nt.size()) {
                return false;
            }
            for (int i = 0; i < ns.size(); ++i) {
                if (ns[i] != nt[i]) {
                    return false;
                }
            }
            return true;
        }
    };