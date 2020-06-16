# 使用递归解决问题，使用时传入剩下的字符串以及还有的位数，每次递归的时候计算使用1-3位是否合法，然后往下调用即可

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        
        def cal(sub, num):
            # print ("cal", sub, num)
            if (num == 0 or len(sub) == 0):
                if (num == 0 and len(sub) == 0):
                    return [[]]
                else:
                    return []
            result = []
            for i in range(1, 4):
                s = sub[:i]
                subresult = []
                # print ("转换", s)
                ints = int(s)
                if (i == 1):
                    if (ints >= 0 and ints <= 9):
                        subresult = cal(sub[i:], num - 1)
                elif (i == 2):
                    if (ints >= 10 and ints <= 99):
                        subresult = cal(sub[i:], num - 1) 
                elif (i == 3):
                    if (ints >= 100 and ints <= 255):
                        subresult = cal(sub[i:], num - 1)
                for sr in subresult:
                    result.append([s] + sr)
            return result  
        totalresult = []
        for tr in cal(s, 4):
            # print ("结果", tr)
            totalresult.append(".".join(tr))
        return totalresult