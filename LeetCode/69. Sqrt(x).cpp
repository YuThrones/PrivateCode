// 经典二分逼近，需要注意int溢出问题，不能用乘法只能用除法
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int start = 0;
        int end = x;
        int mid = 0;
        while(start <= end) {
            mid = (start + end) / 2;
            if (mid < x / mid) {
                start = mid + 1;
            }
            else if (mid > x / mid) {
                end = mid - 1;
            }
            else {
                break;
            }
        }
        if (mid * mid > x) {
            return mid - 1;
        }
        return mid;
    }
};