// 最初想法是用k长度的数组存一下后半段的数，然后挪前半段，最后再把后半段放回去就行
// 看了下答案，其实有O(n)空间复杂度的方法，只需要把前后半段分别逆序，然后整体逆序就行，时间复杂度一样是O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if ((nums.size() <= 1) || k == 0) {
            return;
        }
        
        int temp[k];
        for (int i = 0; i < k; ++i) {
            temp[i] = nums[nums.size() - k + i];
        }
        for (int i = nums.size() - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
    
};