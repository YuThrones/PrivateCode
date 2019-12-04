# 子问题递归求解，每次把已有的列表按照倒序依次加上最前面的二进制代表的数字，然后插入列表中
# 因为子问题已经是连续的，按照反序加一位也是连续的，因此这样就可以保证连续性
# 每个子问题调用一次次方，这里是可以优化的，改成子问题放回自己的次方，乘以2就好了，不过影响不大
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if (n == 0):
            return [0]
        sub = self.grayCode(n - 1)
        length = len(sub)
        ext = pow(2,n-1)
        for index in range(length - 1, -1, -1):
            sub.append(ext+sub[index])
        return sub

# 看了下其他人的解法，非常的简单，可以直接把一个数的普通二进制表示变成GrayCode
# 只需要 (num >> 1) ^ num即可，也就是右移一位然后与自己做异或，这个思路其实挺难理解的
# 我画了尝试了几个数，大概的原理应该是，通过相邻位的异或，来排除进位同时对多个位置的变化影响
# 比如1101,1110这两个二进制表示的数，用这种方法算出来的GrayCode是1011和1001，可以看到，只有进位终止的那一位发生了变化
# 再极端一点的，01111，10000这两个二进制表示的数，对应的GrayCode分别是01000,11000，也是只有进位终止那一位发生了变化
# 原理就是进位时连续一段数字都会从0、1变成1、0，所以相邻异或是一样的
# 至于GrayCode转换成二进制数字，则比较麻烦，下面是网上贴出的Java函数，思路其实就是根据第一位的数字，然后利用相邻两位的异或，逐位还原结果
unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}