class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> total(27, 0);
        vector<int> sub(27, 0);
        int result = 0;
        for (auto c : chars) {
            total[c - 'a']++;
        }
        for (auto& w : words) {
            sub.assign(27, 0);


            bool isOk = true;
            for (auto c : w) {
                int index = c - 'a';
                sub[index]++;
                if (sub[index] > total[index]) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                result += w.length();
            }
        }
        return result;
    }
};