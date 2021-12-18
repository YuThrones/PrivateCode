// 题目不复杂，只有两个点需要稍微煮一下：
// 第一是可以用乘以-1或者1来表示正负值
// 第二是判断是否溢出，可以通过int最大值减去当前余数除以10是否比当前数小来判断，效果和当前数乘以10之后加上余数是一直的

class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        x = abs(x);
        int res = 0;
        
        while (x > 0)
        {
            if ((INT32_MAX - x % 10) / 10 < res) { return 0; }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res * sign;
    }
};