#include <vector>
#include <map>
#include <ranges> // 用于views::drop(1)，C++20及以上支持
using namespace std;

class Solution {
public:
    // 核心功能：计算数组中最长递增子序列(LIS)的个数
    // 算法思路：贪心+有序map优化，时间复杂度O(n log n)，比基础DP的O(n²)快
    // 核心思想：用map维护{子序列末尾值: {该末尾值对应的LIS长度, 该长度的计数}}，利用map有序性快速查找前驱，实时清理无效条目
    int findNumberOfLIS(vector<int>& nums) {
        // 1. 边界条件：空数组直接返回0
        if (nums.empty()) return 0;

        // 全局变量定义
        short longestLen = 1;          // 记录当前找到的最长LIS长度（用short节省内存，提升缓存效率）
        int output = 1;                // 最终结果：最长LIS的个数
        // map的键：子序列的末尾值；值：pair<以该值结尾的LIS长度, 该长度的LIS个数>
        // map底层是红黑树，天然有序，支持O(log k)的查找/插入（k是map当前大小）
        map<int, pair<short, int>> seq;

        // 2. 初始化：第一个元素单独处理，自身构成长度为1的LIS，计数为1
        seq.emplace(nums.front(), pair<short, int>{1, 1});

        // 3. 遍历数组中除第一个外的所有元素（views::drop(1)跳过第一个元素）
        for (int n : nums | views::drop(1)) {
            // 3.1 查找第一个≥n的元素迭代器（lower_bound是map的核心高效操作，O(log k)）
            // 作用：找到n可以接在哪个前驱元素的后面形成更长的LIS
            auto it = seq.lower_bound(n);

            // 情况1：没找到等于n的元素（it指向末尾 或 it->first≠n）
            if (it == seq.end() || it->first != n) {
                // 子情况1.1：it是map开头（说明没有比n小的元素）
                if (it == seq.begin()) {
                    // n自身构成长度1的LIS，插入map，计数1
                    it = seq.emplace_hint(it, n, pair<short, int>{1, 1});
                    continue; // 处理下一个元素
                }
                // 子情况1.2：有比n小的前驱元素
                else {
                    // 取前驱元素的长度+1作为当前n的LIS长度，继承前驱的计数
                    auto prevIt = prev(it); // 前驱迭代器（比n小的最大元素）
                    short newLen = prevIt->second.first + 1;
                    int newCount = prevIt->second.second;
                    // emplace_hint：利用已有迭代器提示插入位置，比普通emplace更快
                    it = seq.emplace_hint(it, n, pair<short, int>{newLen, newCount});

                    // 更新全局最长长度和结果计数
                    if (newLen >= longestLen) {
                        if (newLen > longestLen) { // 找到更长的LIS，重置结果
                            longestLen = newLen;
                            output = newCount;
                        } else { // 长度等于当前最长，累加计数
                            output += newCount;
                        }
                    }
                }
            }
            // 情况2：找到等于n的元素（it->first == n）
            else {
                // 子情况2.1：it是map开头（没有比n小的元素）
                if (it == seq.begin()) {
                    it->second.second++; // 长度1的LIS计数+1
                    continue;
                }
                // 子情况2.2：前驱元素的长度≥当前n的长度（说明需要更新n的长度和计数）
                else if (prev(it)->second.first >= it->second.first) {
                    auto prevIt = prev(it);
                    it->second.first = prevIt->second.first + 1; // 更新长度
                    it->second.second = prevIt->second.second;   // 继承前驱计数

                    // 更新全局最长长度和结果计数
                    if (it->second.first >= longestLen) {
                        if (it->second.first > longestLen) {
                            longestLen = it->second.first;
                            output = it->second.second;
                        } else {
                            output += it->second.second;
                        }
                    }
                }
                // 子情况2.3：前驱元素的长度 == 当前n的长度-1（说明有多个前驱能形成相同长度的LIS）
                else if (prev(it)->second.first == it->second.first - 1) {
                    int addCount = prev(it)->second.second; // 前驱的计数
                    // 如果当前长度是最长长度，结果先累加
                    if (it->second.first == longestLen) output += addCount;
                    it->second.second += addCount; // 累加前驱的计数到当前n的计数
                }

                // 3.2 处理多个前驱的情况：向前遍历所有长度为（当前长度-1）的元素，累加计数
                bool isLongest = (it->second.first == longestLen); // 标记当前是否是最长长度
                if (isLongest) output -= it->second.second; // 先减去旧的计数，避免重复

                auto prevIt = prev(it); // 从紧邻的前驱开始遍历
                // 向前找所有长度为（当前长度-1）的元素，累加计数
                while (prevIt != seq.begin() && (--prevIt)->second.first == it->second.first - 1) {
                    it->second.second += prevIt->second.second;
                }

                if (isLongest) output += it->second.second; // 加回更新后的计数

                // 3.3 清理无效条目：删除map中后续长度更小的元素（贪心策略，保留更小的末尾值即可）
                // 这些条目无意义，清理后减少map大小，提升后续查找效率
                auto nextIt = next(it);
                while (next(it) != seq.end() && it->second.first > next(it)->second.first) {
                    seq.erase(next(it));
                }
            }
        }

        // 4. 最终结果处理：如果最长长度是1（所有元素相等或递减），则个数等于数组长度
        return (longestLen == 1) ? nums.size() : output;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen = 1;
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                ans += count[i];
            }
        }
        return ans;
    }
};