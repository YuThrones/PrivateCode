class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for(string& s : cpdomains) {
            auto space = s.find(' ');
            int num = stoi(s.substr(0, space));
            
            int last = space;
            count[s.substr(last + 1, s.length() - last - 1)] += num;
            for(int i = space + 1; i < s.length(); ++i) {
                if (s[i] == '.') {
                    last = i;
                    count[s.substr(last + 1, s.length() - last - 1)] += num;
                }
            }
        }

        vector<string> ans;
        for(auto& it : count) {
            ans.push_back(to_string(it.second) + " " + it.first);
        }
        return ans;
    }
};