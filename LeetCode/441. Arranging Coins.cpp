// 二分搜索就可以解决问题，注意边界就行

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while(left <= right) {
            long long mid = (left + right) >> 1;
            if ((1 + mid) * mid >> 1 > n) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};