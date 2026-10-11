// 正常思路过不了，超时了
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int highestScore = 0;
        for(int k = 0; k < n; ++k) {
            int score = 0;
            for(int i = 0; i < n; ++i) {
                int temp = nums[(i + n + k) % n];
                // cout << k << " " << i << " " << temp << endl;
                if (temp <= i) {
                    score++;
                }
            }
            if (score > highestScore) {
                highestScore = score;
                ans = k;
            }
        }
        return ans;
    }
};


// ds给的答案，复杂度只有O(N)，核心是算出每个位置的数能加分的k的范围
// 然后用差分数组存储，用前缀和方式求解
// 我自己没有理清楚，但是ds理清楚之后又感觉没那么复杂，主要还是没想到
// 不过哪怕我理清楚了，可能也不会想到差分数组的方式，最多理清楚边界条件，没办法这么简洁
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        // 差分数组：diff[i] 表示第 i 个 k 相对于第 i-1 个 k 的分数变化量
        // 多开 1 位是为了方便处理区间右边界 +1 的情况（避免越界）
        vector<int> diff(n + 1, 0);

        // 遍历原数组的每个元素，计算它对哪些旋转次数 k 有分数贡献
        for (int i = 0; i < n; ++i) {
            int v = nums[i];

            // 情况一：v <= i，此时元素有可能在 k <= i 和 k > i 两段都贡献分数
            if (v <= i) {
                // 子情况 1a：当 k <= i 时，新位置 pos = i - k
                // 要求 pos >= v  =>  i - k >= v  =>  k <= i - v
                // 所以 k 在区间 [0, i - v] 内都满足条件
                diff[0] += 1;                  // 区间左端点 +1
                diff[i - v + 1] -= 1;          // 区间右端点后一位 -1

                // 子情况 1b：当 k > i 时，新位置 pos = i - k + n
                // 要求 pos >= v  =>  i - k + n >= v  =>  k <= i + n - v
                // 又因为 k 最大为 n-1，所以区间为 [i + 1, min(n - 1, i + n - v)]
                int left = i + 1;
                int right = min(n - 1, i + n - v);
                if (left <= right) {           // 区间有效才更新
                    diff[left] += 1;
                    diff[right + 1] -= 1;
                }
            }
            // 情况二：v > i，此时只有 k > i 时才有可能满足条件
            else {
                // 新位置 pos = i - k + n，要求 pos >= v
                // 即 i - k + n >= v  =>  k <= i + n - v
                // 且 k 必须大于 i，所以区间为 [i + 1, i + n - v]
                int left = i + 1;
                int right = i + n - v;
                // 注意：right 一定小于 n（因为 v > i => i + n - v < n），所以无需 min
                if (left <= right) {
                    diff[left] += 1;
                    diff[right + 1] -= 1;
                }
            }
        }

        // 利用差分数组还原每个 k 的得分，并找出最高分对应的最小 k
        int score = 0;          // 当前 k 的得分
        int maxScore = -1;      // 记录历史最高分
        int ans = 0;            // 最高分对应的最小 k

        for (int k = 0; k < n; ++k) {
            score += diff[k];   // 前缀和得到当前 k 的总分
            if (score > maxScore) {
                maxScore = score;
                ans = k;        // 因为 k 从小到大遍历，第一个达到最大值的即为最小 k
            }
        }

        return ans;
    }
};