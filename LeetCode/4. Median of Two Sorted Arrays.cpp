// 总体思路是一趟归并过程，两个vector的index指向的节点哪边小哪边index增加，指向后面的数，如果一边没有节点了，就只增加另一个vector的index
// 需要对两个vector的size的和作不同的讨论，如果是奇数，则两边加起来拿到的第size/2+1个数就是我们要的中位数
// 如果是偶数，则两边加起来找到的第size/2和 size/2+1个数是我们要找到的数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        int index = 0;
        int index1 = 0;
        int index2 = 0;
        int medianIndex = size / 2;
        if (size % 2 == 1) {
            // 总数是奇数，只需要找到第size/2 + 1个数
            while(index <= medianIndex) {
                if (index1 < size1 && (index2 >= size2 || nums1[index1] < nums2[index2])) {
                    if (index == medianIndex) {
                        return nums1[index1];
                    }
                    index1 += 1;
                }
                else {
                    if (index == medianIndex) {
                        return nums2[index2];
                    }
                    index2 += 1;
                }
                index += 1;
            }
        }
        else {
            // 总数是偶数，需要找到第size/2 和size/2 + 1这两个数的平均值
            int lastNum = 0;
            while(index <= medianIndex) {
                if (index1 < size1 && (index2 >= size2 || nums1[index1] < nums2[index2])) {
                    if (index == medianIndex) {
                        return (double(nums1[index1]) + double(lastNum)) / 2;
                    }
                    lastNum = nums1[index1];
                    index1 += 1;
                }
                else {
                    if (index == medianIndex) {
                        return (double(nums2[index2]) + double(lastNum)) / 2;
                    }
                    lastNum = nums2[index2];
                    index2 += 1;
                }
                index += 1;
            }
            
        }
        return 0;
    }
};