// 遍历找元音，存一下下标逆转就行

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vec;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a'
                || s[i] == 'e'
                || s[i] == 'i'
                || s[i] == 'o'
                || s[i] == 'u'
                || s[i] == 'A'
                || s[i] == 'E'
                || s[i] == 'I'
                || s[i] == 'O'
                || s[i] == 'U'
               )
            {
                vec.push_back(i);
            }
        }
        
        int n = vec.size();
        string temp;
        int l, r;
        for (int i = 0; i < n / 2; ++i) {
            l = vec[i];
            r = vec[n - i - 1];
            temp = s.substr(l, 1);
            s.replace(l, 1, s.substr(r, 1));
            s.replace(r, 1, temp);
            // cout << l << " " << r << " " << s << endl;
        }
        return s;
    }
};