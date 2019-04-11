# 主要思路是从大到小除和求余，并且余数要判断是否有特殊显示，然后连接即可
class Solution:
    def intToRoman(self, num: int) -> str:
        div_list = [
            (1, "I"),
            (5, "V"),
            (10, "X", {4:"IV", 9:"IX",}),
            (50, "L"),
            (100, "C", {4:"XL", 9:"XC",}),
            (500, "D"),
            (1000, "M", {4:"CD", 9:"CM",}),
        ]
        result = ""
        index = len(div_list) - 1
        while (index >= 0):
            remainder = num % div_list[index][0]
            trade = num // div_list[index][0]
            if (trade > 0):
                result += trade * div_list[index][1]
            # print (num, index, div_list[index][0], remainder, trade)
            if (len(div_list[index]) == 3):
                # print ("check")
                for sub in div_list[index][2]:
                    sub_div = div_list[index][0] // 10
                    if (sub_div != 0 and remainder // sub_div == sub):
                        # print (">>", sub)
                        remainder -= sub * sub_div
                        result += div_list[index][2][sub]
            num = remainder
            index -= 1
        return result