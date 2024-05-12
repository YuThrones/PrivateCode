// 主要是区分首位字母分类讨论就行

#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCapital = word[0] >= 'A' && word[0] <= 'Z';
        int capital = 0;
        int notCapital = 0;
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] >= 'A' && word[i] <= 'Z') ++capital;
            if (word[i] >= 'a' && word[i] <= 'z') ++notCapital;
            if (!firstCapital && capital) return false;
            if (firstCapital && capital > 0 && notCapital > 0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    sol.detectCapitalUse("FlaG");
    return 0;
}