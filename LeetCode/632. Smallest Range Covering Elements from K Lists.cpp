// 这道题自己没好思路，以为是递归，但是想了想都不太行
// 问了下deepseek，给的思路是先把每个数组第一个数都放进去，得到一个最初区间，然后用一个最小堆维护，
// 每次弹出一个最小的，然后在对应数组补一个数进去，把边界往右推，这个做法其实挺巧妙的
// 不过跟最佳答案比还是不够快，两个原因：1. 用的vector<int>，其实tuple就足够了。2. 他的算法复杂度比我高一点，但是常数小，而且cache优化

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int k = nums.size();
        int right = -1000000;
        for(int i = 0; i < k; ++i) {
            pq.push({nums[i][0], i, 0});
            right = max(right, nums[i][0]);
        }
        vector<int> ans{-1000000, 1000000};
        while(!pq.empty()) {
            auto& top = pq.top();
            if(right - top[0] < ans[1] - ans[0]) {
                ans[0] = top[0];
                ans[1] = right;
            }
            int i = top[1];
            int j = top[2];
            if(j >= nums[i].size() - 1) {
                break;
            }
            else {
                pq.pop();
                pq.push({nums[i][j + 1], i, j + 1});
                right = max(right, nums[i][j + 1]);
            }
        }
        return ans;
    }
};

// 最佳答案
// 核心思路是把所有数组合并到一个队列里面排序，虽然复杂度高一点，但是cpu缓存命中优化，而且内存分配次数少。
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const auto m{nums.size()};
        array<pair<int, int>, 3500 * 50> arr;
        array<int, 3500> freq;
        size_t n{};
        
        memset(freq.data(), 0, sizeof(int) * m);
        for (int i{}; i != m; ++i) {
            for (const auto num : nums[i]) {
                arr[n++] = {num, i};
            }
        }
        ranges::sort(arr | views::take(n), {}, [](const auto& p) {
            return p.first;
        });
        
        auto c{arr[0].first};
        auto d{arr[n - 1].first};
        auto l2{d - c};
        for (size_t r{}, l{}, cnt{}; r != n; ++r) {
            auto&& [b, id_r]{arr[r]};
            if (++freq[id_r] == 1)
                ++cnt;
            
            while (cnt == m) {
                auto&& [a, id_l]{arr[l++]};
                if (const auto l1{b - a}; l1 < l2 || l1 == l2 && a < c) {
                    c = a;
                    d = b;
                    l2 = l1;
                }
                    
                if (--freq[id_l] == 0)
                    --cnt;
            }
        }
        return {{c, d}};
    }
};