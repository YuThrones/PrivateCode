// 这道题其实只要想清楚，一个字母占用一位，两个以上，用数字表示，必然比原本占用的少这件事，就可以遍历的过程中直接修改走过的位置
// 比如，aa表示为a2，只需要两位，当数字表示需要3位时，至少也是a10了，远比原本的少，想清楚这个问题之后，这道题就很简单了

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (!chars.size()) return 0;
        int index = 0;
        char lastChar = chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == lastChar) {
                ++count;
                continue;
            }
            
            string countStr = to_string(count);
            chars[index++] = lastChar;
            if (count > 1) {
                for (int j = 0; j < countStr.length(); ++j) {
                    chars[index + j] = countStr[j];
                }
                index += countStr.length();
            }

            lastChar = chars[i];
            count = 1;
        }

        chars[index++] = lastChar;
        if (count > 1) {
            string countStr = to_string(count);
            for (int j = 0; j < countStr.length(); ++j) {
                chars[index + j] = countStr[j];
            }
            index += countStr.length();
        }
        
        return index;
    }
};


int main() {
    vector<char> chars{'a','a','b','b','c','c','c'};
    Solution sol;
    sol.compress(chars);
    return 0;
}