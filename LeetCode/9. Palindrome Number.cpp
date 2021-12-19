// 直接用vector逆序存起来对比就行，不过速度不够快，看了下最快答案，直接使用long long存，绕过了int的限制。。。
// 思路是一样的，也没什么技巧性
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            vector<int> v1 = vector<int>();
            
            int temp = x;
            int y = 0;
            while (temp > 0) {
                v1.push_back(temp % 10);
                temp /= 10;
            }
            for (int i = 0; i < v1.size() / 2; ++i) {
                if (v1[i] != v1[v1.size() -1 - i]) {
                    return false;
                }
            }
            return true;
        }
    };