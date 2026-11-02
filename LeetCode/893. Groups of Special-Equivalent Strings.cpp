// 答案很容易想到，就是把每个string转成一个唯一的字符串统计就行，只是不同方法速度不同
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(string& word : words) {
            cnt[convert(word)]++;
        }
        
        return cnt.size();
    }

    string convert(string& word) {
        vector<char> odd;
        vector<char> even;
        for(int i = 0; i < word.length(); ++i) {
            if (i % 2 == 0) {
                even.push_back(word[i]);
            }
            else {
                odd.push_back(word[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        string temp = word;
        for(int i = 0; i < word.length(); ++i) {
            if (i % 2 == 0) {
                temp[i] = even[i / 2];
            }
            else {
                temp[i] = odd[i / 2];
            }
        }
        return temp;
    }
};

// 最佳答案，简洁很多，而且不需要vector，更快,循环也比我少
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;

        for (auto& w : words) {
            string even, odd;
            for (int i = 0; i < (int)w.size(); i++) {
                if (i % 2 == 0) even += w[i];
                else            odd += w[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(even + "|" + odd);   // canonical signature
        }
        return groups.size();
    }
};