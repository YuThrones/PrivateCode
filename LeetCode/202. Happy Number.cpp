// 思路是比较清晰的，哈希表记录一下使用过的数，按照规则循环，遇到使用过的或者1停下来即可

#include<iostream>
#include<cmath>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
        unordered_set<int> s;

        while(temp != 1 && s.find(temp) == s.end()) {
            s.insert(temp);
            int res = 0;
            int t = temp;
            while(t) {
                res += pow(t % 10, 2);
                t /= 10;
            }
            temp = res;
        }

        return temp == 1;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isHappy(2) << endl;
    cout << s.isHappy(19) << endl;
    return 0;
}