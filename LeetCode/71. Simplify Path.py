# 可以直接用一个栈存储实际可用的部分，无论是//还是. ，只需要忽略即可，然后把实际有效的部分拼接起来，加上root的/就行。
class Solution:
    def simplifyPath(self, path: str) -> str:
        string_list = []
        for sub in path.split("/"):
            if (sub == "" or sub == "/" or sub == "."):
                continue
            if (sub == ".."):
                string_list = string_list[:-1]
                continue
            string_list.append(sub)
            
        return "/" + "/".join(string_list)