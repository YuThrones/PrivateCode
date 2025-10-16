class Solution {
public:
    string makeGood(string s) {
        int dis = 'a' - 'A';
        // cout << dis << endl;
        int i = 0;
        while(s.length() > 0 && i < s.length() - 1) {
            // cout << i << " " << s << " " << s[i + 1] - s[i] << endl; 
            if (abs(s[i + 1] - s[i]) == dis) {
                s.erase(i, 2);
                i = max(i - 1, 0);
            }
            else {
                i += 1;
            }
        }
        return s;
    }
};