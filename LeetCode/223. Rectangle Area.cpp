// 比较简单，先判断有没有交集，如果没有直接返回和，如果有减去重叠部分就行

#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int total = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1);
        if (ax2 <= bx1) return total;
        if (ay2 <= by1) return total;
        if (bx2 <= ax1) return total;
        if (by2 <= ay1) return total;
        return total - (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
    }
};

int main() {
    Solution s;
    s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    return 0;
}



