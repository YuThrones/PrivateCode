class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp = "";
        for(auto &w : words) {
            if (temp.length() < s.length()) {
                temp += w;
            }
            else {
                break;
            }
        }
        return temp == s;
    }
};