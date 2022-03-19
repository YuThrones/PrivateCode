// 最开始想到的肯定是根据题意，一个一个与，但是发现在数字范围很大的时候太慢了
// 接着想到，每个位置，把左区间和右区间当前位置的数与一下，如果为1且两个区间差值小于当前位置的base，则说明当前位置是1（因为说明区间内所有数当前位置都一样）
// 看了下最快答案，思路是类似的，但是更加优雅，对比左右区间，一旦不同就右移，直到相同位置，这样相当于把右边不同的数字去去掉了，然后再左移回原来位数

#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0){
            return 0;
        }
        int count= 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m<<count;
    }

    int rangeBitwiseAnd(int left, int right) {
        int base = 1;
        int res = 0;
        int sub = right - left;
        for (int i = 0; i < 31; ++i) {
            if (sub < base && (left & base) && (right & base)) {
                res |= base;
            }
            if (i < 30) {
                base *= 2;            
            }
        }
        return res;
    }

    int rangeBitwiseAnd2(int left, int right) {
        int res = INT_MAX;
        for (int i = left; i <= right; ++i) {
            res &= i;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    int count = 10000;
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (s.rangeBitwiseAnd(i, j) != s.rangeBitwiseAnd2(i, j)) {
                cout << i << " " << j << " === " << s.rangeBitwiseAnd(i, j) << " " << s.rangeBitwiseAnd2(i, j) << endl;
            }
        }
    }
    return 0;
}