// 这道题其实思路很容易想到，就是尝试一个点作为起点，走一圈看看能不能找到环，需要记录两个数据，第一个是这个点是否走过，第二个是这个点是否在当前环中
// 有两个地方需要注意，第一个是题目要求环的正负符号必须相同，第二个是出现值不在0到n-1中间的需要调整到范围内

#include<vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> record(n, false);
        int flag = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (record[i]) continue;

            flag = nums[i] > 0? 1 : -1;

            int j = (i + nums[i]) % n;
            while(j < 0) j += n;


            vector<bool> visited(n, false);
            visited[i] = true;
            record[i] = true;
            int last = i;
            while(!record[j] && !visited[j] && flag * nums[j] > 0) {
                record[j] = true;
                visited[j] = true;
                last = j;
                j = (j + nums[j]) % n;
                while(j < 0) j += n;
            }
            if (visited[j] && last != j) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // vector<int> nums{2,-1,1,2,2};
    // vector<int> nums{-1,-2,-3,-4,-5,6};
    // vector<int> nums{1,-1,5,1,4};
    // vector<int> nums{2,-1,1,-2,-2};
    // vector<int> nums{-2,1,-1,-2,-2};
    // vector<int> nums{-1, -1, -1};
    vector<int> nums{-2,-3,-9};
    Solution sol;
    bool res = sol.circularArrayLoop(nums);
    
    return 0;
}