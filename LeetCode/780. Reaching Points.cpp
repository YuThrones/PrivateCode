// 这道题正向递归思路是一下子就能写出来，但是会超时很多
// 很容易想到反过来思考，路径唯一，不需要两条路径尝试，但是还是会超时
// 核心在于不要一次减一个，当tx > ty的时候，上一次一定是 (tx - ty, ty)，这里可能会重复出现多次
// 这时候应该多次，合并，也就是上一次是（tx % ty, ty），这样就可以达标了


class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;

            if (tx > ty) {
                if (ty == sy) {
                    // 纵坐标已经到位，横坐标只能靠不断减 ty 来逼近 sx
                    return (tx - sx) % ty == 0;
                }
                tx %= ty;
            } else if (ty > tx) {
                if (tx == sx) {
                    return (ty - sy) % tx == 0;
                }
                ty %= tx;
            } else {
                // tx == ty 且不是起点，无法再倒推
                return false;
            }
        }
        return false;
    }
};