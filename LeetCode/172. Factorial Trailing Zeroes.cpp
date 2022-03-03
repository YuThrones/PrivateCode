// 我的思路是，统计2和5的数量，然后取最小值就行了
// 看了下最快答案，更狠，只检查5的倍数，因为2一定是够的，所以更快。
class Solution {
public:
    int trailingZeroes(int n) {
        int num2 = 0;
        int num5 = 0;
        int temp;
        while(n > 0) {
            temp = n;
            while(temp % 2 == 0) {
                ++num2;
                temp /= 2;
            }
            while(temp % 5 == 0) {
                ++num5;
                temp /= 5;
            }
            --n;
        }
        return min(num2, num5);
    }
};