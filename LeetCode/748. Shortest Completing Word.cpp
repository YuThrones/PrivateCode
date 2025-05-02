class Solution {
    public:
        string shortestCompletingWord(string licensePlate, vector<string>& words) {
            vector<int> count(27, 0);
            for (auto c : licensePlate) {
                if (c >= 'a' && c <= 'z') {
                    count[c - 'a'] += 1;
                }
                else if (c >= 'A' && c <= 'Z') {
                    count[c - 'A'] += 1;
                }
            }
    
            string result = "";
            for (auto word : words) {
                vector<int> cnt(27, 0);
                for (auto c : word) {
                    if (c >= 'a' && c <= 'z') {
                        cnt[c - 'a'] += 1;
                    }
                    else if (c >= 'A' && c <= 'Z') {
                        cnt[c - 'A'] += 1;
                    }
                }
                bool isOk = true;
                for (int i = 0; i < 27; ++i) {
                    if (count[i] > cnt[i]) {
                        isOk = false;
                        break;
                    }
                }
                if(!isOk) {continue;}
    
                if (result.size() == 0 || result.size() > word.size()) {
                    result = word;
                }
            }
            return result;
        }
    };