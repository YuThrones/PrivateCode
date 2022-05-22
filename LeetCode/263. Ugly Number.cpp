// 把这个数的2、3、5因子都除去就可以
// 看了下速度比最快算法慢，因为他把limit作为类变量，节省了多次操作的时间

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return false;
        
        vector<int> limit{2, 3, 5};
        
        for (auto l: limit) {
            while(n % l == 0) n /= l;
        }
        
        return n == 1;
    }
};