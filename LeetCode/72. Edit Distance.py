# 这道题第一眼看就是递归，但是没想清楚递归要怎么做。看了https://www.dreamxu.com/books/dsa/dp/edit-distance.html之后，基本能理解思路
# 核心思路就是，从前往后也好，从后往前也好，字符不同时在每个位置上面只有三种操作方案，删去当前位置，在当前位置插入，替换当前位置，只要想明白这点，就能写出基本的递归
# 但是基本的递归对大量子问题做了重复的计算，因此需要改成动态规划。使用矩阵的动态规划第一时间是比较好想到的，需要仔细思考的是如果节省空间
# 文中讲的很明白，关键是计算顺序，事实上矩阵中一个位置的值计算只需要上、左、左上三个位置的值就可以了，因此单个时间只需要存储一行的数据即可。
# 感觉上这个解法已经是很快了，不过在leetcode上跑只有80%，看了下最优解，思路还是动态规划，但是实现上有所不同
# 最优解是使用deque，把三种可能的操作push进去，然后使用set来排除已经搜索过的可能性，并且在中间一直对比当前两个字符串本身，看是否相等，相等就可以提前结束，速度上快2倍，不过理解稍微难一点点
# 我试着加入了对比相同，提前结束的代码，但是速度并没有变快，可能对比字符串的时间也比较慢
# 最优解放在下面作为参考
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        d = []
        len1 = len(word1)
        len2 = len(word2)
        for i in range(len2 + 1):
            d.append(i)
            
        old = 0
        temp = 0
        for i in range(1, len1 + 1):
            old = d[0]
            d[0] = i
            
            for j in range(1, len2 + 1):
                temp = d[j]
                if (word1[i - 1] == word2[j - 1]):
                    d[j] = old
                else:
                    d[j] = min(min(old + 1, d[j - 1] + 1), temp + 1)
                old = temp
        return d[len2]

# class Solution:
#     # others' best
#     def minDistance(self, word1: str, word2: str) -> int:
#         from collections import deque
#         visit, q=set(), deque([(word1, word2, 0)])
#         while True:
#             w1, w2, d=q.popleft()
#             if (w1, w2) not in visit:
#                 if w1==w2:
#                     return d
#                 visit.add((w1, w2))
#                 while w1 and w2 and w1[0]==w2[0]:
#                     w1, w2=w1[1:], w2[1:]
#                 d+=1
#                 q.extend([(w1[1:], w2[1:], d), (w1, w2[1:], d), (w1[1:], w2, d)])
