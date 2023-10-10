// 一开始想法是直接用深度优先搜索，但是超时了
// 后面看了下思路，需要结合具体数字分析，可以发现有的数字有独特字母，先把这些筛选之后，剩下的数字又有独特字母，按这个思路可以全部筛选完（多么幸运），然后再用数组这些加速

static const auto Initialize = [] {
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
    return nullptr;  
  }();

class Solution {
  const int DIGS[10] = {0, 2, 4, 6, 8, 5, 7, 3, 9, 1},
            CHARS[10] = {25, 22, 20, 23, 6, 5, 18, 7, 8, 14};
  const vector<vector<int>> REMS = {{14}, {14}, {5, 14}, {18, 8}, {8, 7},
                                    {8},  {},   {},      {},      {}};

public:
  string originalDigits(string s) {
    int fmap[26] = {0}, ans[10] = {0};
    for (char c : s)
      fmap[c - 97]++;
    for (int i = 0; i < 10; i++) {
      int count = fmap[CHARS[i]];
      for (int rem : REMS[i])
        fmap[rem] -= count;
      ans[DIGS[i]] = count;
    }
    string ansstr;
    for (int i = 0; i < 10; i++) {
      char c = (char)(i + 48);
      for (int j = ans[i]; j; j--)
        ansstr += c;
    }
    return ansstr;
  }
};

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string digitStr[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};


class Solution {
public:
    // bool allZero(unordered_map<char, int>& digitMap) {
    //     auto it = digitMap.begin();
    //     for (; it != digitMap.end(); ++it) {
    //         if (it->second != 0) return false;
    //     }
    //     return true;
    // }

    // string dp(unordered_map<char, int>& digitMap, int startNum) {
    //     for (int i = startNum; i < 10; ++i) {
    //         bool canDelete = true;
    //         for (auto &c: digitStr[i]) {
    //             digitMap[c] -= 1;
    //             if (digitMap[c] < 0) 
    //                 canDelete = false;
    //         }
    //         if (canDelete) {
    //             if (allZero(digitMap)) {
    //                 return to_string(i);
    //             }
    //             string subRes = dp(digitMap, i);
    //             if (allZero(digitMap)) {
    //                 return to_string(i) + subRes;
    //             }
    //             for (auto &c: digitStr[i]) {
    //                 digitMap[c] += 1;
    //             }
    //         }
    //         else {
    //             for (auto &c: digitStr[i]) {
    //                 digitMap[c] += 1;
    //             }
    //         }
    //     }
    //     return "";
    // }

    // string originalDigits(string s) {
    //     unordered_map<char, int> digitMap;
    //     for (auto &c: s) {
    //         digitMap[c] += 1;
    //     }
    //     return dp(digitMap, 0);
    // }

    string originalDigits(string s) {
        // unordered_map<char, int> digitMap;
        int digitMap[200] = {};
        for (auto &c: s) {
            digitMap[c] += 1;
        }
        vector<int> ans(10, 0);
        // 第一轮清洗，取出有独特字母的0 2 4 6 8
        if (digitMap['z'] > 0) {
            ans[0] += digitMap['z'];
            subNum(digitMap, 0, digitMap['z']);
        }
        if (digitMap['w'] > 0) {
            ans[2] += digitMap['w'];
            subNum(digitMap, 2, digitMap['w']);
        }
        if (digitMap['u'] > 0) {
            ans[4] += digitMap['u'];
            subNum(digitMap, 4, digitMap['u']);
        }
        if (digitMap['x'] > 0) {
            ans[6] += digitMap['x'];
            subNum(digitMap, 6, digitMap['x']);
        }
        if (digitMap['g'] > 0) {
            ans[8] += digitMap['g'];
            subNum(digitMap, 8, digitMap['g']);
        }
        // 第二次清洗掉剩余的有独特字母的1 3 5 7
        if (digitMap['o'] > 0) {
            ans[1] += digitMap['o'];
            subNum(digitMap, 1, digitMap['o']);
        }
        if (digitMap['h'] > 0) {
            ans[3] += digitMap['h'];
            subNum(digitMap, 3, digitMap['h']);
        }
        if (digitMap['f'] > 0) {
            ans[5] += digitMap['f'];
            subNum(digitMap, 5, digitMap['f']);
        }
        if (digitMap['s'] > 0) {
            ans[7] += digitMap['s'];
            subNum(digitMap, 7, digitMap['s']);
        }
        // 最后剩下的就是9
        ans[9] += digitMap['e'];
        string str;
        for (int i = 0; i < 10; ++i) {
            str += string(ans[i], '0' + i);
        }
        return str;
    }

    void subNum(int (&digitMap)[], int num, int count) {
        for (auto &c: digitStr[num]) {
            digitMap[c] -= count;
        }
    }
};

int main() {
    Solution s;
    // string input = "zeroonetwothreefourfivesixseveneightnine";
    // string input = "onethreefivesevennine";
    string res = s.originalDigits(input);
    return 0;
}