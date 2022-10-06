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

        int choose = (n - 1) / 2 % 2 == 0 ? n - 1 : n + 1;
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
        return min(res1, res2) + 1;
    }
    
};

int main() {
    Solution sol;

    for (int i = 1; i < 10001; ++i) {
        if (sol.integerReplacement(i) != sol.integerReplacement2(i)) {
            cout << i << " " << sol.integerReplacement(i) << " " << sol.integerReplacement2(i) << endl;
            break;
        }
    }
    return 0;
}