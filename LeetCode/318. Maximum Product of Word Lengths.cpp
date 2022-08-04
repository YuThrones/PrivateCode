// 这道题的核心点是解决怎么比较两个字符串的重复字母问题，因为只有26个字母，很容易想到直接用bitmap的方式，直接用一个int表示哪些字母出现了哪些没有，然后与运算即可
// 最快答案也是这个思路，但是进一步做了优化，每个相同的int只保留最大长度的那个字符串，其实就可以理解为做了剪枝

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> record;
        for (auto w: words) {
            int temp = 0;
            for (auto c: w) {
                temp |= (1 << (c - 'a'));
            }
            record.push_back(temp);
        }
        
        for (int i = 0; i < record.size(); ++i) {
            for (int j = 0; j < record.size(); ++j) {
                if ((record[i] & record[j]) == 0) {
                    res = max(res, int(words[i].length() * words[j].length()));
                }
            }
        }
        
        return res;
    }
};