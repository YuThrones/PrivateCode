class Solution {
    public:
        bool checkRecord(string s) {
            int A = 0;
            int L = 0;
            for (auto c : s) {
                if (c == 'A') {
                    ++A;
                }
                else if (c == 'L') {
                    ++L;
                    if (L >= 3) {return false;}
                    continue;
                }
                if (A >= 2) { return false; }
                L = 0;
            }
            return true;
        }
    };