class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dct(27, 0);
        for (int i = 0; i < order.length(); ++i) {
            dct[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); ++i) {
            bool isEqual = true;
            int size = min(words[i - 1].size(), words[i].size());
            for (int j = 0; j < size; ++j) {
                if (dct[words[i - 1][j] - 'a'] > dct[words[i][j] - 'a']) {
                    return false;
                }
                if (dct[words[i - 1][j] - 'a'] < dct[words[i][j] - 'a']) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                if (words[i - 1].size() > words[i].size()) {
                    return false;
                }
            }
        }
        return true;
    }
};