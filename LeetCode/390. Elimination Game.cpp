// 没做出来，笨办法超时了，其实看了下答案，思想还是递归，自己被左右限制住了，本质还是递归，然后数字转化的问题

class Solution {
    public:
        int lastRemaining(int n) {
            return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));    
        }
    };

#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        int lastRemaining(int n) {
            if (n < 1) {return 0;}
            vector<int> temp(n, 0);
            int index = 0;
            int count = 0;
            int step = 1;
            while(count < n - 1) {
                int last = 0;
                for(; (index >= 0) && (index < n); index += step) {
                    if (temp[index] == 1) {continue;}
                    last = 1-last;
                    if (last == 0) {continue;}
                    ++count;
                    temp[index] = 1;
                    // cout << index << endl;
                }
                step = -step;
                if (step > 0) {
                    index = 0;
                }
                else {
                    index = n - 1;
                }
                // cout << step << " " << index << " " <<count << endl;
            }
            for (int i = 0; i < n; ++i) {
                if (temp[i] == 0) {return i + 1;}
            }
            return 0;
        }
    };

int main() {
    Solution s;
    for (int i = 1 ; i < 100; ++i) {
        cout << i << " " << s.lastRemaining(i) <<endl;
    }
    return 0;
}