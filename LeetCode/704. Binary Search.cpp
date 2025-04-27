class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size();
            while(start < end) {
                int mid = (start + end ) / 2;
                // cout << start << " " << mid << " " << end << endl;
                if (nums[mid] == target) {
                    return mid;
                }
                if (nums[mid] > target) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }
            return -1;
        }
    };