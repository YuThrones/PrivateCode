class Solution {
    public:
        string decodeString(string s) {
            // vector<char> collect;
            // decode(s, collect, 0);
            // string result(collect.begin(), collect.end());
            // return result;
            int index = 0;
            int outIndex = 0;
            return decode(s, 0, outIndex);
        }
    
        string decode(string &s, int index, int& outIndex) {
            if (index >= s.length()) {
                outIndex = index;
                return "";
            }
            int num = 0;
            string result = "";
            string temp;
            while(index < s.length()) {
                if (s[index] == '[') {
                    temp = decode(s, index + 1, outIndex);
                    index = outIndex;
                    for (int i = 0; i < num; ++i) {
                        result += temp;
                    }
                    num = 0;
                }
                else if (s[index] == ']') {
                    outIndex = index + 1;
                    return result;
                }
                else if (s[index] >= '0' && s[index] <= '9') {
                    num = num * 10 + (s[index] - '0');
                    ++index;
                }
                else
                 {
                    num = num > 0 ? num : 1;
                    result += s[index] * num;
                    ++index;
                    num = 0;
    
                }
            }
            outIndex = index;
            return result;
        }
    };