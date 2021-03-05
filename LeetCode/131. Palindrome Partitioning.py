# 我的思路是使用Manacher算法先算出每个位置对应的最大回文数半径，然后利用这个来判断所有区间是否是回文数
# 最后用递归每次左右拆分，在保证左边是回文数的情况下计算右边即可得出结果

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        convert_str = self.add_split(s)
        length = len(convert_str)
        rd = [0] * length

        center = 0
        max_right = 0
        for i in range(length):
            mirror = 2 * center - i
            rd[i] = min(rd[mirror], max_right - i)

            while((i - rd[i]) >= 0 and (i + rd[i]) < length and convert_str[i + rd[i]] == convert_str[i - rd[i]]):
                next_range = rd[i] + 1
                if not ((i - next_range) >= 0 and (i + next_range) < length and convert_str[i + next_range] == convert_str[i - next_range]):
                    break
                rd[i] += 1

            if i + rd[i] > max_right:
                max_right = i + rd[i]
                center = i
        
        ori_len = len(s)
            
        repeat = {}
        
        def is_palindrome(start, end):
            return rd[start + end + 1] >= (end - start)
        
        def cal(start, end):
            if (start, end) in repeat:
                return repeat[(start, end)]
            if end - start == 0:
                repeat[(start, end)] = [[s[start]]]
                return [[s[start]]]
            new_res = []
            for div in range(start, end):
                
                # 判断左边部分是否是回文数
                if not is_palindrome(start, div):
                    continue
                
                
                right = cal(div + 1, end)
                for sub_right in right:
                    new_res.append([s[start:div + 1]] + sub_right)
            if is_palindrome(start, end):
                new_res.append([s[start:end + 1]])
            repeat[(start, end)] = new_res
            return new_res
            
        return cal(0, ori_len-1)
        
    def add_split(self, input_str):
        split_str = '#'
        if split_str in input_str:
            raise Exception
        return '#' + split_str.join(list(input_str)) + '#'