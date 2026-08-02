#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for(auto &s : words){
            // 枚举s所有后缀，从第二个字符开始，删掉集合里存在的后缀
            for(int i = 1; i < s.size(); i++){
                st.erase(s.substr(i));
            }
        }
        int ans = 0;
        for(auto &s : st){
            ans += s.size() + 1; // +1代表 #
        }
        return ans;
    }
};