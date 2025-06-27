class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (auto c : address) {
            if (c == '.') {
                res += '[';
                res += c;
                res += ']';
            }
            else {
                res += c;
            }
        }
        return res;
    }
};