// 感觉是一个冒泡的题目，但是ac之后速度很慢
// 看了下，发现没用的交换太多了，中间0的部分可以直接跳过

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) continue;
            cur = max(cur, i + 1);
            while (cur < n && nums[cur] == 0)
                cur++;
            if (cur == n)
                break;
            swap(nums[i], nums[cur]);
            cur++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = nums.size() - 1;
        while(r >= 0 && !nums[r]) --r;
        int l = r - 1;
        while(l >= 0) {
            if (nums[l]) --l;
            else {
                for (int j = l; j < r; ++j) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
    
    inline void swap(int& a, int& b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};