// 挺简单的，把更大的从num2拷贝到nums1就行，前面的不用动
// 看了下最佳答案，有点复杂，没看懂什么意思，实际提交测试好像也没有更快，暂时不管
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[n + m - 1] = nums2[n - 1];
                --n;
            }
            else {
                nums1[n + m - 1] = nums1[m - 1];
                --m;
            }
        }
        
        while(n > 0) {
            nums1[n - 1] = nums2[n - 1];
            --n;
        }
    }
};