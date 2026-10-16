// 我的方法是直接统计刚好和为goal的数组开始位置，然后遍历判断开头是否是0进行统计，最差情况是O(n)
// 最佳答案是统计最多和为goal - 1 和 goal，然后做差就得出和恰好为 goal 数量
// 好处是他只需要最后的坐标和第一个坐标位置就能算数量，因此复杂度只是O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int total = 0;
        int start = 0;
        for(int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            while(total > goal) {
                total -= nums[start];
                ++start;
            }
            if (total == goal && start <= i) {
                ++ans;
                for(int j = start; j < i; ++j) {
                    if (nums[j] != 0) {
                        break;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // by sliding window
        auto atMost = [&](int goal){
        if (goal < 0) return 0;
        int ans = 0, low = 0, sum = 0;
        for(int high = 0; high<nums.size(); high++){
            sum+=nums[high];
            while(sum > goal){
                sum -= nums[low];
                low++;
            }
            ans += high - low + 1;
        } 
        return ans;
    };
    return atMost(goal) - atMost(goal-1);
    }
};