#include <unordered_map>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        // 关键！大数直接返回1，防止栈溢出
        if(n >= 4475) return 1.0;
        unordered_map<int, unordered_map<int, double>> rec;
        return cal(n, n, rec);
    }

    double cal(int a, int b, unordered_map<int, unordered_map<int, double>>& rec) {
        // 缓存命中
        if(rec.find(a) != rec.end()) {
            if (rec[a].find(b) != rec[a].end()) {
                return rec[a][b];
            }
        }
        double ans = 0;
        if (a <= 0 && b <= 0) {
            ans = 0.5;
        }
        else if (a <= 0) {
            ans = 1;
        }
        else if (b <= 0) {
            ans = 0;
        }
        else {
            ans += 0.25 * cal(a - 100, b - 0, rec);
            ans += 0.25 * cal(a - 75, b - 25, rec);
            ans += 0.25 * cal(a - 50, b - 50, rec);
            ans += 0.25 * cal(a - 25, b - 75, rec);
            // ✅ 只有a>0,b>0才存缓存！边界case不存入map
            rec[a][b] = ans;
        }
        return ans;
    }
};