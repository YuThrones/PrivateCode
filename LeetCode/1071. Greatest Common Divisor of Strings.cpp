// 这题暴力做不难，但是一时确实没想到好的办法。
// 看了下最佳答案，是先通过两个判断两个字符颠倒后是否相同判断有没有答案，这个做法确实很巧妙。
// 如果存在相同，只要找两个字符串的最大公共长度就行，太优雅了。

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

         // Check if concatenation property holds
    if (str1 + str2 != str2 + str1) {
        return "";
    }
    // Get gcd of lengths
    int g = gcd((int)str1.size(), (int)str2.size());
    return str1.substr(0, g);
    }
};

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        string temp = "";
        int n = min(str1.length(), str2.length());
        for (int i = 0; i < n; ++i) {
            temp = str1.substr(0, i + 1);
            if (isOk(str1, temp) && isOk(str2, temp)) {
                ans = temp;
            }
        }
        return ans;
    }

    bool isOk(string& s, string& t) {
        // cout << "isok " << s<< " " << t << endl;
        if (s.length() % t.length() != 0) {
            return false;
        }
        string temp;
        temp.reserve(s.length());
        int n = s.length() / t.length();
        for (int i = 0; i < n; ++i) {
            temp += t;
        }

        // cout << "isok?? " << s<< " " << temp << endl;

        for (int i = 0; i < s.length(); ++i) {
            if(s[i] != temp[i]) {
                return false;
            }
        }
        // cout << "isok!! " << s<< " " << t << endl;
        return true;
    }
};