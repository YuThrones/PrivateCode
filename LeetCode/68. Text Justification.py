# 把题目拆解，分两步。
# 第一步，找到单行最多能容纳的单词数
# 第二步，将找到的这些单词用空格拼接
# 于是思路就比较清楚了，维护一个当前行的单词的列表，并每两个之间预留一个空格的位置，如果已有单词的长度加上预留空格长度之后，余下的长度不足以放入下一个单词了，那么就可以对这部分进行拼接
# 按这个方法遍历整个输入列表之后，列表里面还会剩下最后一行的单词，这时候按靠左排列，只留一个空格的格式拼接好即可
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        current_list = []
        length_count = 0
        num_count = 0
        result = []
        for word in words:
            length = len(word)
            if (length_count + num_count + length > maxWidth):
                result.append(self.getString(current_list, maxWidth, length_count))
                current_list = [word]                
                num_count = 1
                length_count = length
            else:
                current_list.append(word)
                num_count += 1
                length_count += length
        result.append(self.getLastString(current_list, maxWidth))
        return result    
            
    def getString(self, words, width, length_count):
        # print ("getString", words, width, length_count)
        string = words[0]
        space = len(words) - 1
        if (space == 0):
            return string + (width - length_count) * " "
        space_length = width - length_count
        average = space_length // space
        left = space_length % space
        for i in range(space):
            if (i < left):
                string += (average + 1) * " "
            else:
                string += average * " "
            string += words[i + 1]
        return string
    
    def getLastString(self, words, width):
        # print ("getLastString", words, width)
        string = words[0]
        for word in words[1:]:
            string += " " + word
        need_space = width - len(string)
        string += " " * need_space
        return string