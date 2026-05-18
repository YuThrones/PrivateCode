// 重新构建了一个string还是相对慢了，而且+=耗时，最佳答案直接永远的resize，确实更快

class Solution {
public:
    string makeFancyString(string s) {
        int j=0;
        if(s.size()<3) return s;
      for(int i=0;i<s.size()-2;i++)  {
        if(s[i]==s[i+1] && s[i]==s[i+2]){
        continue;
        }
        else {
            s[j]=s[i];
            j++;
        }
      }
      s[j]=s[s.size()-2];
      j++;
      s[j]=s[s.size()-1];
      j++;
      
      s.resize(j);
      return s;
    }
};

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(auto c : s) {
            if (ans.length() < 2 || 
            !(c == ans[ans.length() - 1] && c == ans[ans.length() - 2])) {
                ans += c;
            }
        }
        return ans;
    }
};