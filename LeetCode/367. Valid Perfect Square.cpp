// 为了避免使用long和溢出，写的有点别扭，如果只是为了过，直接用long二分更简洁

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) return true;
        int l = 1;
        int r = num / 2 + 1;
        while(l < r) {
            int m = (l + r) / 2;
            int left = num / m;
            if (left > m) {
                l = m + 1;
            }
            else if (left < m) {
                r = m - 1;
            }
            else if (left * m == num) {
                return true;
            }
            else if (left * m < num) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        if ((INT_MAX / l > l) && (l * l == num)) {
            return true;
        }

        if ((INT_MAX / r > r) && (r * r == num)) {
            return true;
        }
        return false;
    }
};