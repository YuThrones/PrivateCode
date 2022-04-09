// 其实如果不考虑首尾相连的情况，就是一个很简单的动态规划
// 最开始有点钻入死胡同了，事实上首尾相连的情况，只需要考虑，以0开始到n - 2这个序列的最大rob值，和以1开始到n-1位置的最大rob值，取更大那个就好

#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
//     int rob(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return nums[0];
//         }
        
//         return max(process(nums, 0, nums.size() - 1), process(nums, 1, nums.size()));
//     }
    
//     int process(vector<int>& nums, int start, int end) {
//         if (start >= end) {
//             return 0;
//         }
//         return max(process(nums, start + 2, end) + nums[start], process(nums, start + 1, end));      
//     }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int record1[nums.size() - 1];
        int record2[nums.size() - 1];
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            record1[i] = nums[i];
            record2[i] = nums[i + 1];
            if (i + 2 < nums.size() - 1) {
                record1[i] += record1[i + 2];
                record2[i] += record2[i + 2];
            }

            if (i + 1 < nums.size() - 1) {
                record1[i] = max(record1[i], record1[i + 1]);
                record2[i] = max(record2[i], record2[i + 1]);
            }
        }
        return max(record1[0], record2[0]);
    }
};


int main() {
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    Solution s = Solution();
    cout << s.rob(test) << endl;;
    return 0;
}