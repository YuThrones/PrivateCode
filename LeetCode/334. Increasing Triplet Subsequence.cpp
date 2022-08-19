// 按我理解，就是一道简化的找最大递增子序列的问题，最快答案也只是用了变量，没什么区别

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> record;
        record.push_back(INT_MAX);
        int start;
        int end;
        int mid;
        int index;

        for (int i = 0; i < nums.size(); ++i) {
            start = 0;
            end = record.size();
            // 二分搜索
            while(start < end) {
                mid = (start + end) / 2;
                if (record[mid] < nums[i]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            
            index = start - 1;
            if (index >= 0) {
                if (index < record.size() - 1) {
                    record[index + 1] = nums[i];
                }
                else {
                    record.push_back(nums[i]);
                }
            }
            else {
                record[0] = nums[i];
            }
            if (record.size() >= 3) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> in{1, 2, 3, 4, 5};
    cout << sol.increasingTriplet(in);
    return 0;
}