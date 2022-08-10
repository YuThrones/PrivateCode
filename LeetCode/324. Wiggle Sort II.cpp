// 这道题我用完美洗牌问题解，好像还不太行，存在数字相同的问题，看答案，好像根本不用完美洗牌，只需要前后分好段，然后从前往后扫描，尽可能让奇数位更大就行？

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
                // write your code here
        int m = nums.size()/2;
        nth_element(nums.begin(), nums.begin()+m, nums.end());
        int pivot = nums[m];
        
        int i = 0;
        int o = 1;
        int e = (nums.size()-1) % 2 == 0 ? nums.size()-1 : nums.size()-2;
        //cout << m;
        while (i < nums.size()) {
            // 当i处理偶数位时，保证偶数位找到一个合适的奇数位存放
            if (nums[i] > pivot && (i % 2 == 0 || i > o)) {
                swap(nums[i], nums[o]);
                o += 2;
                continue;
            }

            // 当i处理奇数位时，保证奇数位的数找到一个合适的偶数位存放
            if (nums[i] < pivot && (i % 2 == 1 || i < e)) {
                swap(nums[i], nums[e]);
                e -= 2;
                continue;
            }

            // 当i走过一遍，可以保证把大于等于中位数的都放偶数位，其他放奇数位
            // 对于等于pivot的，到底有没有问题，还需要思考下
            i++;
        }
    }
};


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        // 完美洗牌问题，长度满足3 ^ k - 1才能完美循环替换
        process(nums, 0, nums.size());
        finalSwap(nums);
    }

    void process(vector<int>& nums, int start, int end) {
        int len = end - start;
        if (len <= 1) return;
        
        // 把区间分割成 [0, nearValue) 和 [nearValue, end)两段，前面可以直接用循环完美移动，后面继续分隔        
        int nearValue = near(len);
        if (nearValue < len) {
            int mid = start + (end + 1 - start) / 2;

            rangeSwap(nums, start + nearValue / 2, mid, mid + nearValue / 2);
        }
        loopSwap(nums, start, start + nearValue);
        process(nums, start + nearValue, end);
    }

    int near(int value) {
        // 求出小于等于value的最大的3 ^ k - 1
        int res = 1;
        while (res * 3 <= value + 1) {
            res *= 3;
        }
        return res - 1;
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void reverse(vector<int>& nums, int start, int end) {
        int temp;
        for (int i = 0; i < (end - start) / 2; ++i) {
            temp = nums[start + i];
            nums[start + i] = nums[end - 1 - i];
            nums[end - 1 - i] = temp;
        }
    }

    void rangeSwap(vector<int>& nums, int start, int mid, int end) {
        reverse(nums, start, mid);
        reverse(nums, mid, end);
        reverse(nums, start, end);
    }

    void loopSwap(vector<int>& nums, int start, int end) {
        int len = end - start;
        
        for (int k = 1; start + k < end; k *= 3) {
            int first = k;
            int last = nums[start + first - 1];
            int index = first * 2 % (len + 1);
            while (index != first) {
                swap(last, nums[start + index - 1]);
                index = index * 2 % (len + 1);
            }
            swap(last, nums[start + first - 1]);
        }
    }

    void finalSwap(vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    // int count = 27;
    // for (int i = 1; i < count; ++i) {
    //     nums.push_back(i);
    // }
    nums = {1,1,2,1,2,2,1};
    nums = {4,5,5,6};
    // sol.loopSwap(nums, 0, nums.size());
    // sol.finalSwap(nums);
    sol.wiggleSort(nums);
    return 0;
}