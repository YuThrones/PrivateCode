// 这道题的思路我想到了，就是先算出可以n1个s1可以处理多少个s2，然后再处理一下n2就行
// 可以先用一个函数算出第一次成功处理完s2时停留的位置index1，然后等再次处理完一个s2且当时记录的index1 % str1.length()与上一次相同时，我们就可以认为出现了循环
// 这时候就是一个完整的s1循环可以处理一个完整的s2循环，也就是说我们这时候可以根据此时消耗的s1数量和处理的s2数量，把输入的n1减少为只剩尾部的长度
// 然后根据停留的index1余数相同，可以算出尾部字符串，然后执行原始的计算就行
// 麻烦的是要写好边界条件，比较考验coding
// 但是还是比最快答案慢一点点，我看了下最快答案，思路有点类似又不太一样，他求的是每次完整的使用一次s1，处理的s2有多少个，剩下的残余s2索引是多少，然后也是用n1和n2先计算完整处理的，然后计算参与
// 总的来说这道题思路不算很难想到，但是边界条件很容易写错，比较考验coding

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // 先判断是否存在解
        for (int i = 0; i < s2.length(); ++i) {
            if (s1.find(s2[i]) == string::npos) {
                return 0;
            }
        }

        vector<int> cal = yu(s1, s2);
        // 计算s1可以完整的处理多少个s2
        int cost = (n1 * s1.length() - cal[0]) / s1.length() / cal[1] * cal[1];
        int handle = cost / cal[1] * cal[2] + 1;
        string left = "";
        if (cal[0] % s1.length() != 0) {
            for (int i = cal[0] % s1.length(); i < s1.length(); ++i) {
                left += s1[i];
            }
        }
        int rest = n1 - cost - ((cal[0] - 1) / s1.length() + 1);
        for (int i = 0; i < rest; ++i) {
            left.append(s1);
        }
        int ans = yu2(left, s2);
        ans += handle;
        return ans / n2;
    }
    
    vector<int> yu(string str1, string str2) {
        // 第一次处理完一个s2的时候的index1
        // 刚好处理完一个循环消耗多少个s1
        // 刚好处理完一个循环消耗多少个s2
        vector<int> ans(3);
        int index1 = 0;
        int index2 = 0;
        
        while(true) {
            if (str1[index1 % str1.length()] == str2[index2 % str2.length()]) {
                ++index2;
            }
            ++index1;
            
            if (index2 % str2.length() == 0 && index2 != ans[2]) {
                // 余数相同则刚好处理完一个循环
                if (ans[0] == 0) {
                    ans[0] = index1;
                    ans[2] = index2;
                }
                else if(index1 % str1.length() == ans[0] % str1.length()) {
                    ans[1] = (index1 - ans[0]) / str1.length();
                    ans[2] = (index2 - ans[2]) / str2.length();
                    break;
                }
            }
        }
        
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << endl;
        }
        return ans;
    }
    
    int yu2(string str1, string str2) {
        int ans = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] == str2[ans % str2.length()]) {
                ++ans;
            }
        }
        // cout << ans << endl;
        return (ans) / str2.length();
    }
};


int main() {
    Solution solution;

    // string s1 = "acb";
    // int n1 = 4;
    // string s2 = "ab";
    // int n2 = 2;
    // string s1 = "aaa";
    // int n1 = 3;
    // string s2 = "aa";
    // int n2 = 1;
    // string s1 = "acb";
    // int n1 = 1;
    // string s2 = "acb";
    // int n2 = 1;
    // string s1 = "baba";
    // int n1 = 11;
    // string s2 = "baab";
    // int n2 = 1;
    string s1 = "aaa";
    int n1 = 20;
    string s2 = "aaaaa";
    int n2 = 1;
    cout << solution.getMaxRepetitions(s1, n1, s2, n2) << endl;
}



class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> rapport(102,-1);
        vector<int> rest(102,-1);
        int b=-1;int posRest=0;int rap=0;
        int last=-1;
        rapport[0]=rest[0]=0;
        for(int i=1;i<=s2.size()+1;i++){
            int j;
            for(j=0;j<s1.size();j++){
                if(s2[posRest]==s1[j]){
                    posRest++;
                    if(posRest==s2.size()){
                        rap++;
                        posRest=0;
                    }
                }
            }
            for(int k=0;k<i;k++){
                if(posRest==rest[k]){b=k;last=i;break;}
            }
            rapport[i]=rap;rest[i]=posRest;
            if(b>=0)break;
        }
        int interval=last-b;
        if(b>=n1)return rapport[n1]/n2;
        return ((n1-b)/interval*(rapport[last]-rapport[b])+rapport[(n1-b)%interval+b])/n2;  }
};