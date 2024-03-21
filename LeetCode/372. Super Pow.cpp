// 关键在于不能直接用pow，要每一步都对base作mod，才能防止溢出

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int powMod(int base, int exponent, int mod) {
        base %= mod;
        int result = 1;
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent >>= 1;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        int mod = 1337;
        return (powMod(superPow(a, b), 10, mod) * powMod(a, last, mod)) % mod;
    }
};

int main() {
    Solution sol;
    vector<int> vec{3};
    int res = sol.superPow(2, vec);
    return 0;
}
