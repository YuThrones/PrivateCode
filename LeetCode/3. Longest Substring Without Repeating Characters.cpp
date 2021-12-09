// 从前往后遍历的时候把每个字母对应的index记录下来，如果遇到了map里面有的且index在当前len的包裹之内，说明发生了重复，则把字符串的长度缩短到上次遇到这个字母的下一位开始到当前位置的长度
// 如果遇到的字母是map里面没有的或者index已经不在当前len之内，直接把字母的index记录进去，然后长度+1即可。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> record = map<char, int>();
        int ans = 0;
        int i = 0;
        int len = 0;
        for (i = 0; i < s.length(); ++i) {
            map<char, int>::iterator iter = record.find(s[i]);
            if (iter == record.end() || i - iter->second > len) {
                record[s[i]] = i;
                // record.insert(pair<string, int>(s[i], i));
                len += 1;
                if (len > ans) {
                    ans = len;
                }
            }
            else {
                len = i - iter->second;             
                iter->second = i;
            }
        }
        return ans;
    }
};