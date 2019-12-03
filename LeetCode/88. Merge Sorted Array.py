# 数组归并，注意下把数组多余的位抹去就行
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        length = len(nums1)
        index1 = 0
        index2 = 0
        for _ in range(m):
            while(index2 < n and nums2[index2] < nums1[index1]):
                nums1.insert(index1, nums2[index2])
                index1 += 1
                index2 += 1
            index1 += 1
        while(index2 < n):
            nums1[index1] = nums2[index2] 
            index1 += 1
            index2 += 1
        while(len(nums1) > m + n):
            nums1.pop(-1)
                