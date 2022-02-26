// 之前看教程学习了可以使用N+1个桶，把所有数字分到N+1个桶中，这样差值必然出现在相邻桶，因为必然存在一个空桶，导致差值大于每个桶的区间
// 这样可以把复杂度降为O(n)
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minNum) {
                minNum = nums[i];
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
            }
        }
        
        if (maxNum == minNum) {
            return 0;
        }
        
        int minArray[nums.size() + 1];
        int maxArray[nums.size() + 1];
        for (int i = 0; i <= nums.size(); ++i) {
            minArray[i] = INT_MAX;
            maxArray[i] = INT_MIN;
        }
        
        float sub = maxNum - minNum;
        float part = sub / (nums.size() + 1);
        cout << "part" << part << endl;
        for (int i = 0; i < nums.size(); ++i) {
            int index = ((float)(nums[i] - minNum) / part);
            index = min(index, (int)nums.size());
            if (nums[i] < minArray[index]) {
                minArray[index] = nums[i];
            }
            
            if (nums[i] > maxArray[index]) {
                maxArray[index] = nums[i];
            }
        }

        int maxGap = 0;
        int lastMax = INT_MIN;
        for (int i = 0; i <= nums.size(); ++i) {
            if (minArray[i] == INT_MAX) {
                continue;
            }
            if (lastMax != INT_MIN && minArray[i] - lastMax > maxGap) {
                maxGap = minArray[i] - lastMax;
            }
            lastMax = maxArray[i];
        }
        
        return maxGap;
    }
};

int main() {
    vector<int> in;
    in.push_back(3);
    in.push_back(6);
    in.push_back(9);
    in.push_back(1);
    Solution s = Solution();
    cout << s.maximumGap(in);
    return 0;
}