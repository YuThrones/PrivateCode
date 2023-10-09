// 这道题确实难，自己没想出来，看了下gpt的答案，思路是要分类讨论，要解决的问题有三个：
//     1. 密码长度大于等于6，小于等于20
//     2. 密码里面必须包含大写字母，小写字母，数字
//     3. 密码不能连续重复大于等于3次
// 我们可以执行三种操作：
//     1. 删除
//     2. 插入
//     3. 替换
// 第一种操作可以解决问题1和问题3，第二种操作可以解决三种问题，问题三可以解决问题2和问题3
// 对字符串的长度分类讨论：
//     1. 长度小于6，这种情况是一定要插入的，而插入也可以同时解决重复和类型丢失的问题，长度1-4，插入一个一定能解决重复问题，如果有5个重复，那么也意味着条件2必然不满足，因为一定少了两种类型，所以要插入两个，因此只要返回缺失类型数量和需要插入补充长度数量的最大值即可
//     2. 长度大于等于6小于等于20的情况，选择不需要改变成都的操作3，只需要解决重复和类型缺失，这种情况下，解决重复一定能顺带解决类型缺失，因此返回两者最大值即可
//     3. 长度大于20的，必然是优先用删除操作，因为这样可以在解决重复问题的时候顺带解决长度问题，如果重复的数字可以表示为3的倍数加上一个余数，最佳方法是先删除到3n + 2的表示，这样可以保证最大限度的利用替换的效果，比如5个连续重复字符只需要一次替换就可以解决重复问题，没必要删除到3，因为需要的替换次数相同。所以先尽量高效利用必须的删除操作删到只剩20个字符，然后再用替换操作即可

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int missingTypes = 3;
        if (any_of(password.begin(), password.end(), ::isdigit)) missingTypes--;
        if (any_of(password.begin(), password.end(), ::islower)) missingTypes--;
        if (any_of(password.begin(), password.end(), ::isupper)) missingTypes--;

        int totalChanges = 0;
        int oneChange = 0;
        int twoChange = 0;
        int i = 2;
        while (i < n) {
            if (password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                int length = 2;
                while (i < n && password[i] == password[i - 1]) {
                    length++;
                    i++;
                }
                totalChanges += length / 3;
                if (length % 3 == 0) oneChange++;
                else if (length % 3 == 1) twoChange++;
            } else {
                i++;
            }
        }

        if (n < 6) {
            return max(missingTypes, 6 - n);
        } else if (n > 20) {
            int deleteCount = n - 20;
            totalChanges -= min(deleteCount, oneChange * 1) / 1;
            totalChanges -= min(max(deleteCount - oneChange, 0), twoChange * 2) / 2;
            totalChanges -= min(max(deleteCount - oneChange - 2 * twoChange, 0), totalChanges * 3) / 3;
            return deleteCount + max(missingTypes, totalChanges);
        } else {
            return max(missingTypes, totalChanges);
        }
    }
};


int main() {
    string input = "ABABABABABABABABABAB1";
    Solution s;
    int res = s.strongPasswordChecker(input);
    return 0;
}