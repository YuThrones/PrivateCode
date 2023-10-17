// 假设s长度为n，p长度为m
// 我的做法是先记录p的每个字母出现的个数，然后单指针从前往后划过，每次拿够m个字母之后比较数量是否相同，最差复杂度为O(mn)
// 看了眼最佳答案，是用双指针来划，在右指针划到某个字母为0时，做一次检查，看看左右指针是否刚好差m位
// 因为右指针的滑动逻辑保证了p里面存在的字母在当前区间必然为非负数个，因此如果长度相等，意味着正好是相同字符串，复杂度为O(m+n)

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        vector<int> mp(26,0);
        for(int i=0;i<p.length();i++) mp[p[i]-'a']++;
        int i=0,j=-1;
        vector<int> ans;
        while(i<n && j<n){
            while(j+1<n && mp[s[j+1]-'a']>0){
                mp[s[j+1]-'a']--;
                j++;
            }
            if(j-i+1==p.length()) ans.push_back(i);
            mp[s[i]-'a']++;
            i+=1;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.length() > s.length()) return res;
        unordered_map<char, int> sMap;
        unordered_map<char, int> pMap;
        for (auto &c: p) {
            pMap[c] += 1;
        }

        for (int i = 0; i < s.length(); ++i) {
            ++sMap[s[i]];
            if (i >= p.length()) {
                --sMap[s[i - p.length()]];
            }
            
            if (i < p.length() - 1) continue;

            bool same = true;
            for (auto it: pMap) {
                if (sMap[it.first] != it.second) {
                    same = false;
                    break;
                }
            }
            if (same) {
                res.push_back(i - p.length() + 1);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = sol.findAnagrams(s, p);
    return 0;
}