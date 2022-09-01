// 我的思路是用manacher算法加速比较，但是速度好像还是不够
// 看了下最快答案，采取的方式是分长度，然后把当前词划分之后直接找其中一部分是否存在对称的词即可，不需要实际拼起来

class Solution {
public:
    // n - # of words
    // k - avg len of words
    // O(nkk), beats O(nnk)
    //
    // group words by length, and sorted groups by length
    // then check every word against word groups shorter
    // for words same len, only add once, because the other counter part will add too
    //
    // same complexity using trie, prefix tree

    // s[l, r] inclusive
    inline bool isPalindrome(const string &s, int l, int r) {
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // groups of words sorted by size
        map<int, unordered_map<string, int>> mm;
        for(int i=0; i<words.size(); i++) {   // O(n*log(k))
            mm[words[i].size()][string(words[i].rbegin(), words[i].rend())] = i;
        }
        
        vector<vector<int>> res;
        for(int i=0; i < words.size(); i++) { // O(n*k*k)
            auto w = words[i];
            
            for(auto & kv : mm) {
                auto & k = kv.first;
                auto & m = kv.second;
                if (k > w.size()) break;
                
                // same len word, add only once, for other word will add again as well
                if (k == w.size()) {
                    if (m.count(w) && m[w] != i) {
                        res.push_back({i, m[w]});
                    }
                    break;
                }
                
                // check back
                if (isPalindrome(w, k, w.size() - 1)) {
                    auto tgt = w.substr(0, k);
                    if (m.count(tgt)) {
                        res.push_back({i, m[tgt]});
                    }
                }

                // check front
                if (isPalindrome(w, 0, w.size() - k - 1)) {
                    auto tgt = w.substr(w.size() - k);
                    if (m.count(tgt)) {
                        res.push_back({m[tgt], i});
                    }
                }
            }
        }

        return res;
    }
};