很简单粗暴，规律就是拿n-1作为N的输入，然后生成N的排列，一个存储表加递归生成搞定
class Solution:
    record = {}
    def countAndSay(self, n: int) -> str:
        if (n in self.record):
            return self.record[n]
        if (n == 1):
            self.record[1] = "1"
            return "1"
        result = ""
        last_result = self.countAndSay(n - 1)
        last = None
        count = 0
        for sub in last_result:
            if (last != sub):
                if (last != None):
                    result += str(count) + last
                last = sub
                count = 1
            else:
                count += 1
        if (last != None):
            result += str(count) + last
        self.record[n] = result
        return result