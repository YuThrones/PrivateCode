# 因为python可以把列表转成元组，然后作为集合的key用来去重，所以可以简单粗暴的先排序，然后递归加上去重解决问题。
# 看了下C++的解法，其实可以不依赖集合去重，思路不要把相同的数字当做单独的元素，而是所有相同的数字都是同一个元素，
# 然后不根据是否有来进行拼接，而是根据有0-n个进行拼接，可以省下集合的空间
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        return self.search(nums, len(nums), set())
        
    def search(self, nums, n, repeat):
        if (n == 0):
            return [[]]
        result = []

        sub = self.search(nums[1:], n-1, repeat)
        for s in sub:
            if (not tuple(s) in repeat):
                repeat.add(tuple(s))
            result.append(s)
            new_list = [nums[0]] + s
            if (not tuple(new_list) in repeat):
                repeat.add(tuple(new_list))
                result.append(new_list)
        return result