# 简单的递归加上记忆
class Solution:
    check_dict = {
        1:["()"]
    }
    def generateParenthesis(self, n: int) -> List[str]:
        if (n in self.check_dict):
            return self.check_dict[n]
        # print (n, self.check_dict)

        small_result = self.generateParenthesis(n-1)
        result = set()
        for sub in small_result:
            # print ("loop1", sub)
            result.add("(" + sub + ")")
        if (n >= 2):
            for small in range(1, n // 2 + 1):
                # print ("loop2", small)
                s1 = self.generateParenthesis(small)
                s2 = self.generateParenthesis(n - small)
                for sub1 in s1:
                    for sub2 in s2:
                        result.add(sub1 + sub2)
                        result.add(sub2 + sub1)
        result = list(result)
        self.check_dict[n] = result
        return result

