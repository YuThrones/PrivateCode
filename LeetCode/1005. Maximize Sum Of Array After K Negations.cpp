class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int minAbs = INT_MAX;
        int minIndex = 0;
        while(k > 0) {
            if (abs(nums[i]) < minAbs) {
                minAbs = abs(nums[i]);
                minIndex = i;
            }
            if (nums[i] < 0) {
                nums[i] = -nums[i];
            }
            else {
                if (k % 2 == 1) {
                    nums[minIndex] = -nums[minIndex];
                }
                break;
            }
            --k;
            if (i + 1 < nums.size()) {
                ++i;
            }
        }

        int result = 0;
        for (auto n:nums) {
            result += n;
        }
        return result;
    }
};