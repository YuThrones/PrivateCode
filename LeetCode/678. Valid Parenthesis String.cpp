// 一开始用递推，时间复杂度太高了过不了，后面查了下可以用贪心，维护最少可能的左括号数量和最大可能的左括号数量，只要low==0说明存在解答

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else if (c == '*') {
                low--;
                high++;
            }
            low = max(low, 0);
            if(high < 0) {return false;}
        }
        return low == 0;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        return check(s, 0, 0);
    }

    bool check(string s, int start, int count) {
        if (count < 0) {return false;}
        if (start >= s.length()) {
            return count == 0;
        }
        if (s[start] == '(') {
            return check(s, start + 1, count + 1);
        }
        else if (s[start] == ')') {
            if (count <= 0) {
                return false;
            }
            return check(s, start + 1, count - 1);
        }
        else if (s[start] == '*') {
            if (check(s, start + 1, count + 1)) {
                return true;
            }
            if (check(s, start + 1, count - 1)) {
                return true;
            }
            if (check(s, start + 1, count)) {
                return true;
            }
        }
        return false;
    }
};