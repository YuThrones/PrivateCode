// 第一反应写递推，但是超时了
// 第二个反应是有规律，直接凑到2的n次方，发现算出来不对
// 最后想了下，可以贪心，只要保证+-1的时候，下一个数有尽量多的偶数因子就行，然后处理下边界情况
// 看了下最快答案，用的是递归加记忆化搜索，确实不需要递推，因为搜索的空间太大了，但是好像复杂度上并没有比我优秀

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }

        if (n == 2) {
            return 1;
        }

        if (n == 3) {
            return 2;
        }

        if (n % 2 == 0) {
            // cout << n / 2 << endl;
            return integerReplacement(n / 2) + 1;
        }
        
        if (n == INT_MAX) {
            return integerReplacement(n / 2 + 1) + 2;
        }

        // 奇数的话往最近的2的n次方走

        int ori = n;
        // n |= n >> 1;
        // n |= n >> 2;
        // n |= n >> 4;
        // n |= n >> 8;
        // n |= n >> 16;
        // n += 1; //大于N的最小的2的N次方
        // int small = n >> 1; //小于N的最大的2的N次方
        // int big = n;
        
        // int choose = (big - ori) * 2 >= (ori - small) ? ori - 1 : ori + 1;
        int choose = (ori - 1) / 2 % 2 == 0 ? ori - 1 : ori + 1;
        // cout << choose << endl;
        return integerReplacement(choose) + 1;
    }

    int integerReplacement2(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return integerReplacement2(n / 2) + 1;
        }

        // 奇数的话往最近的2的n次方走

        int res1 = integerReplacement2(n + 1);
        int res2 = integerReplacement2(n - 1);
        // if (res1 < res2) {
        //     cout << n + 1 << endl;
        // }
        // else {
        //     cout << n - 1 << endl;
        // }

        return min(res1, res2) + 1;
    }
    
};

int main() {
    Solution sol;
    // cout << sol.integerReplacement(1234) << endl;
    // cout << "=================" << endl;
    // cout << sol.integerReplacement(23) << endl;
    // cout << "=================" << endl;
    // cout << sol.integerReplacement2(23) << endl;
    // cout << "=================" << endl;

    for (int i = 1; i < 10001; ++i) {
        if (sol.integerReplacement(i) != sol.integerReplacement2(i)) {
            cout << i << " " << sol.integerReplacement(i) << " " << sol.integerReplacement2(i) << endl;
            break;
        }
    }
    // cout << sol.integerReplacement(200000000) << endl;
    return 0;
}