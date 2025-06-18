// 直接三指针比我统计数量常数更快

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = 0;
        int t = 0;
        while (t < typed.size()) {
            if (n < name.size() && typed[t] == name[n]) {
                n++;
                t++;
            } else if (t > 0 && typed[t] == typed[t-1]) {
                t++;
            } else {
                return false;
            }
        }

        if (n == name.size()) return true;      // Has n parsed all chars in name
        return false;
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(i < name.length() && j < typed.length()) {
            char check = name[i];
            int count1 = 0;
            int count2 = 0;
            while(i < name.length() && name[i] == check) {
                ++count1;
                ++i;
            }
            while(j < typed.length() && typed[j] == check) {
                ++count2;
                ++j;
            }
            if (count1 > count2) {
                return false;
            }
        }
        return (i == name.length()) && (j == typed.length());
    }
};