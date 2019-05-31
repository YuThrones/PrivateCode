# 思路是比较清楚的，不断加自己模拟乘以2，除数指数上升，找到最大值后依次往下减，主要注意细节不写错
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (dividend == 0):
            return 0
        
        result = 0
        if ((dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0)):
            op = 1
        else:
            op = -1
        abs_dividend = abs(dividend)        
        abs_divisor = abs(divisor)
        div = abs_divisor
        div_list = [(1, abs_divisor)]
        if(abs_dividend >= div):
            while(div * 2 <= abs_dividend):
                pow_count, cur_div = div_list[-1]
                div_list.append((pow_count + pow_count, cur_div + cur_div))
                div = cur_div+cur_div
            while(len(div_list) > 0):
                pow_count, cur_div = div_list[-1]
                while(abs_dividend >= cur_div):
                    result += pow_count
                    abs_dividend -= cur_div
                div_list.pop()
        result *= op
        bound = pow(2, 31)
        if (result > bound - 1 or result < -bound):
            return bound-1

        return result
            