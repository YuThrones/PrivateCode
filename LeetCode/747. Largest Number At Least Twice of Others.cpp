class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            int largest = 0;
            int second = 0;
            int index = -1;
            for (int i = 0; i < nums.size(); ++i) {
                int n = nums[i];
                if (n > largest) {
                    second = largest;
                    largest = n;
                    index = i;
                }
                else if (n > second) {
                    second = n;
                }
            }
            return largest >= second * 2 ? index : -1;
        }
    };