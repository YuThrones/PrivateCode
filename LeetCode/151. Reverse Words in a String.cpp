// 先split，然后容器存起来，逆序拼接，最快答案不是vector，是stack，应该差不多
class Solution {
public:
    string reverseWords(string s) {
        vector<string> s_vec = vector<string>();
        int last_index = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (i - last_index > 0) {
                    s_vec.push_back(s.substr(last_index, i - last_index));
                }
                last_index = i + 1;
            }
        }
        if (s.length() - last_index > 0) {
            s_vec.push_back(s.substr(last_index, s.length() - last_index));
        }
        
        string res = "";
        for (int i = s_vec.size() - 1; i >= 0; --i) {
            res += s_vec[i];
            if (i != 0) {
                res += " ";
            }
        }
        
        return res;
    }
};