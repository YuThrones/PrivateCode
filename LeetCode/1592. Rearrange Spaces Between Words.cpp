class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> vec;
        int count = 0;
        int start = -1;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') {
                ++count;
                if (start >= 0) {
                    vec.push_back(text.substr(start, i - start));
                    start = -1;
                }
            }
            else {
                if (start < 0) {
                    start = i;
                }
            }
        }
        if (start >= 0) {
            vec.push_back(text.substr(start, text.length() - start));
        }
        int num = vec.size();
        int space = num > 1 ? count / (num - 1) : 0;
        int left = count - space * (num - 1);
        // cout << count << " " << num << " " << space << " " << left << endl;
        string ans = "";
        for (int i = 0; i < num; ++i) {
            ans += vec[i];
            if (i != num - 1) {
                ans += string(space, ' ');
            }
            else {
                ans += string(left, ' ');
            }
        }
        return ans;
    }
};