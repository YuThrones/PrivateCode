// 不知道为什么第二个常数时间会快一点，奇怪了


class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int m;
        int res;
        while(l < r) {
            m = l + (r - l) / 2;
            res = guess(m);
            if (res == 0) {
                return m;
            }
            else if (res == -1) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        if (l == n) {
            return l;
        }
        return r;
    }
};

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(guess(mid) < 0) r = mid - 1;
            else if(guess(mid) > 0) l = mid+1;
            else return mid;
        }
        return -1;
    }
};