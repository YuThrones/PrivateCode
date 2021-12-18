// 又看了下最佳解法，我想的过于复杂了，按行来，然后算出每一行的所有字符在原字符串的位置然后加起来就行，可以建方程式来计算坐标，再化简就好。
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        int cycle = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += cycle) {
                res += s.at(j);
                if (i > 0 && i < numRows - 1 && cycle - 2 * i + j < s.length()) {
                    res += s.at(cycle - 2 * i + j);
                }
            }
        }
        return res;
    }
};

// 比较简单的逻辑题，能够根据每一个数的index算出他在哪一行，每 numRows * 2 - 2 为一次循环
// 只需要求余就能知道应该在哪一行，然后计算相应在新字符串的偏移，代码应该可以简化
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int cycle = numRows * 2 - 2;
        int remainder = 0;
        int quotient = 0;
        int row = 0;
        int rowcount = 0;
        char res[s.length()];
        int lineindex[numRows];
        int offset = 0;
        for (int i = 0; i < numRows; ++i) {
            lineindex[i] = 0;
        }

        quotient = s.length()/ cycle;
        remainder = s.length() % cycle;
        for (int i = 0; i < cycle; ++i) {
            if (i < numRows) {
                row = i;
            }
            else {
                row = (numRows - 2) - (i - numRows);
            }
            lineindex[row] += quotient;
            lineindex[row] += remainder > i ? 1 : 0;
            
        }
        for (int i = 0; i < numRows; ++i) {
            if (i > 0) {
                lineindex[i] += lineindex[i-1];
            }
        }
        
        for (int i = numRows - 1; i >= 0; --i) {
            if (i > 0) {
                lineindex[i] = lineindex[i-1];
            } else {
                lineindex[0] = 0;
            }
        }
        
        for (int i = 0; i < s.length(); ++i) {
            remainder = i % cycle;
            quotient = i / cycle;
            if (remainder < numRows) {
                row = remainder;
            }
            else {
                row = (numRows - 2) - (remainder - numRows);
            }
            res[lineindex[row]++] = s[i];
        }
        return string(res, s.length());
    }
};