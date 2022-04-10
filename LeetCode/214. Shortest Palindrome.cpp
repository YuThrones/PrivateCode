// 第一反应是用manacher算法，先算出回文数组，然后找出能覆盖左边界的最右index，把这个index的回文右边界右边的部分直接逆转拼接到左边即可
// 但是提交之后超时了，分析了一下，应该是因为转换之后过程中使用的拼接太多，效率太低了，没想出更好办法
// 看了下其他人的答案，他们是用递归来做的，先头尾两个指针往中间走，找到绝对不可能在字符串中找到回文的右半部分，把右半部分逆序拼到左边，然后原本左边的部分递归执行这个函数
// 因为都是在左边加内容，所以结果是正确的

class Solution {
public:
    //Logic: We have to append at start of the string, so how should we decide?
    // we have to find the longest palindrome from the start so that the remaining 
    //string we can append at the first to make it palindrome
    
    //step 1: find out the longest palindrome
    //step 2: append the revesrse of non-palindromic last substring to start
    
    string shortestPalindrome(string s) {
        int n = s.size();
        int st = 0;
        for(int j = n-1;j>=0;j--){
            if(s[st]==s[j])st++;
        }
        if(st==n)return s;
        string revString = s.substr(st);
        reverse(revString.begin(),revString.end());
        return revString + shortestPalindrome(s.substr(0,st))+s.substr(st);
    }
};


#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() == 0) {
            return s;
        }
        
        string str = "";
        for (int i = 0; i < s.length(); ++i) {
            str = str + '#' + s[i];
        }
        str += "#";
        
        int record[str.length()];
        int right = -1;
        int center = -1;
        int index = 0;
        while(index < str.length()) {
            record[index] = index < right ? min(record[2 * center - index], right - index) : 1;
            while(index + record[index] < str.length() && index - record[index] >= 0) {
                if (str[index + record[index]] == str[index - record[index]]) {
                    record[index] += 1;
                }
                else {
                    break;
                }
            }
            if (record[index] > right) {
                right = record[index];
                center = index;
            }
            ++index;
        }
        
        int center_index = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (i - record[i] < 0) {
                center_index = i;
            }
        }

        if (center_index + record[center_index] >= str.length()) {
            return s;
        }
        
        
        // cout << "find " << center_index << endl;
        
        string left = str.substr(center_index + 1, str.length() - center_index - 1);
        reverse(left.begin(), left.end());
        string res = left + str.substr(center_index, str.length() - center_index);
        string ori = "";
        for (int i = 0; i < res.length(); ++i) {
            if (res[i] != '#') {
                ori += res[i];
            }
        }
        
        // cout << "ori " << ori << endl;
        
        // for (int i = 0; i < str.length(); ++i) {
        //     cout << str[i] << " ";
        // }
        // cout << endl;
        
        // for (int i = 0; i < str.length(); ++i) {
        //     cout << record[i] << " ";
        // }
        // cout << endl;
        
        return ori;
    }
};


int main() {
    string input = string(10000, 'a');
    Solution s = Solution();
    s.shortestPalindrome(input);
    return 0;
}