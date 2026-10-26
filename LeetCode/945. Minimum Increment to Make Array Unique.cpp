// 不难想到，最简单就是排序，然后从小到大把相同的处理下就好
// 但是这样不够快，因为数据范围不超过10 ^ 5，所以也很容易想到直接统计数字数量，把排序过程节省
// 复杂度可以从O(nlogn) 降到 O(n)


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                ans += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};

// 最佳答案
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int max = *std::max_element(nums.begin(), nums.end());
        std::vector<int> counts(max + nums.size(), 0);
        for (int num : nums) {
            ++counts[num];
        }

        int result = 0;
        for (int v = 0; v < counts.size() - 1; ++v) {
            if (counts[v] > 1) {
                int duplicates = counts[v] - 1;
                counts[v + 1] += duplicates;
                result += duplicates;
            }
        }

        return result;
    }
};