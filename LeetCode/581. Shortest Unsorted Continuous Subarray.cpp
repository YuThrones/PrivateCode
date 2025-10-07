最容易想到的就是排序，比较下前后哪个坐标不一样就行，不过这样复杂度是O(nlogn)，然后进一步想到前后找一下，有一个小于前面最大值，或者大于后面最小值就行。

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = -1;
        int temp = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < temp) {
                end = i;
            }
            temp = max(temp, nums[i]);
        }
        temp = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] > temp) {
                start = i;
            }
            temp = min(temp, nums[i]);
        }
        if (start == end) {
            return 0;
        }
        return end - start + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(nums.begin(), nums.end());
        int start = -1;
        int end = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] != temp[i]) {
                start = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] != temp[i]) {
                end = i;
                break;
            }
        }
        if (end == start) {
            return 0;
        }
        return end - start + 1;
    }
};