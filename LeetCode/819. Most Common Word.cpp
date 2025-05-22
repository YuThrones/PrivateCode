class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> count;
        set<string> bannedSet;
        for (auto str : banned) {
            std::transform(str.begin(), str.end(), str.begin(),
               [](unsigned char c) { return std::tolower(c); });
            bannedSet.insert(str);
        }
        int start = 0;
        int index = 0;
        string result = "";
        int num = 0;
        paragraph += ' ';
        while(index < paragraph.length()) {
            char c = paragraph[index];
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                if (index > start) {
                    string temp = paragraph.substr(start, index - start);
                    std::transform(temp.begin(), temp.end(), temp.begin(),
                        [](unsigned char c) { return std::tolower(c); });
                    if (bannedSet.find(temp) == bannedSet.end()) {
                        count[temp]++;
                        if (count[temp] > num) {
                            result = temp;
                            num = count[temp];
                        }
                    }
                }
                start = index + 1;
            }
            ++index;
        }

        return result;
    }
};