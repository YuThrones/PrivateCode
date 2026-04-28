// 暴力写法就能过，不过最佳答案做了缓存，穷举c前面a + b可能的答案的数量，少了两层循环，针对范围较小的情况这个优化很实用

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int cnt[201] = {};  // pair sums in [2,200]
        for (int c = 2; c < n - 1; c++) {
            for (int a = 0; a < c - 1; a++)
                cnt[nums[a] + nums[c-1]]++;
            for (int d = c + 1; d < n; d++) {
                int need = nums[d] - nums[c];
                if (need >= 2 && need <= 200) ans += cnt[need];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                for (int c = b + 1; c < n; ++c) {
                    int sum = nums[a] + nums[b] + nums[c];
                    for (int d = c + 1; d < n; ++d) {
                        if (nums[d] == sum) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};