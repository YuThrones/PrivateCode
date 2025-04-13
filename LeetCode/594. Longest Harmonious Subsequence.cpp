// 一开始想到的是统计然后拿，最佳答案是排序然后遍历，算法复杂度是一样的，但是常数时间有差距

#include <vector>
#include <cmath>
#include <map>
using namespace std;

class Solution {
    public:
        int findLHS(vector<int>& nums) {
            if (nums.empty()) {return 0;}
            map<int, int> record;
            for (auto num : nums) {
                if (record.find(num) == record.end()) {
                    record[num] = 1;
                }
                else {
                    ++record[num];
                }
            }
            int result = 0;
            for (auto it : record) {
                int num = it.first;
                int count = it.second;
                if (record.find(num - 1) != record.end()) {
                    result = max(result, record[num - 1] + count);
                }
                if (record.find(num + 1) != record.end()) {
                    result = max(result, record[num + 1] + count);
                }
            }
            return result;
        }
    };

    class Solution {
        public:
            int findLHS(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                int l=0,r=0;
                int ans = 0;
                int n = nums.size();
                for (int i=0;i<n;i++)
                {
                   if(nums[i] - nums[l] == 1)
                   {
                      ans = max(ans,i-l+1);
                   }
        
                   while(nums[i] - nums[l] > 1)
                   {
                     l++;
                   }
                }
                return ans;
            }
        };

int main() {
    Solution s;
    vector<int> in{1,3,2,2,5,2,3,7};
    s.findLHS(in);
    return 0;
}