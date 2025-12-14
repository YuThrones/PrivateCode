class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            return a.length() < b.length();
        });

        vector<string> ans;
        int start = 0;
        for(int end = 1; end <= sentence.length(); ++end) {
            if (end == sentence.length() || sentence[end] == ' ') {
                string temp = sentence.substr(start, end - start);
                bool found = false;
                for(auto& root : dictionary) {
                    if (isRoot(root, temp)) {
                        found = true;
                        ans.push_back(root);
                        break;
                    }
                }
                if(!found) {
                    ans.push_back(temp);
                }
                start = end + 1;
                ++end;
            }
        }

        int totalLen = 0;
        for(auto& s : ans) {
            totalLen += (s.length() + 1);
        }
        totalLen -= 1;

        string ret;
        ret.reserve(totalLen);
        for(int i = 0; i < ans.size(); ++i) {
            ret.append(ans[i]);
            if (i != ans.size() - 1) {
                ret.append(" ");
            }
        }
        return ret;
    }

    bool isRoot(string& root, string& s) {
        if(root.length() > s.length()) {
            return false;
        }
        for(int i = 0; i < root.length(); ++i) {
            if (root[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
};