// 这道题一开始有想到分治，但是没想好递归方式，后面看了下做法其实遍历起点加上mask也能过，不过速度还是不够快。
// 看了下最快答案，跟我一开始的思路类似，不可能满足的位置分割，然后分开处理

#include <string>
#include <unordered_map>
#include <memory.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int count[26];
        int mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            memset(count, 0, sizeof(int) * 26);
            mask = 0;
            for (int j = i; j < s.length(); ++j) {
                int offset = s[j] - 'a';
                ++count[offset];
                if (count[offset] < k) {
                    mask |= (1 << offset);
                }
                else {
                    mask &= ~(1 << offset);
                }
                if (mask == 0) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || n < k) return 0;
        if(k == 1) return n;

        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;

        int i = 0;
        while(i < n && freq[s[i]] >= k) i++;
        if(i == n) return n;

        int left = longestSubstring(s.substr(0,i), k);
        while(i < n && freq[s[i]] < k) i++;
        int right = longestSubstring(s.substr(i), k);

        return max(left,right);
        
    }
};


int main() {
    Solution sol;
    sol.longestSubstring("bbaaacbd",  3);
    return 0;
}