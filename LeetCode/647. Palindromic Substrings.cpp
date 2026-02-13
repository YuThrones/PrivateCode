// 直接遍历所有长度可以得出结果，但是不够快，看了下最快答案，用的是中心拓展法，省略了很多重复比较

class Solution {
public:
    int countSubstrings(string s) {
        
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            int left = i, right = i;
            int curr = 0;
            while((left>=0) && (right < n) && s[left] == s[right]){ // palindromes of odd length
                left--;
                right++;
                curr++;
            }

            left = i, right = i+1;
            while((left>= 0) && (right < n) && s[left] == s[right]){ // palindromes of even lenght
                left--;
                right++;
                curr++;
            }

            ans += curr;

        }
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.length();
        for (int i = 2; i <= s.length(); ++i) {
            for (int j = 0; i + j <= s.length(); ++j) {
                bool ok = true;
                for (int k = 0; k < i / 2; ++k) {
                    if (s[j + k] != s[j + i - k - 1]) {
                        ok = false;
                    }
                }
                if (ok) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};