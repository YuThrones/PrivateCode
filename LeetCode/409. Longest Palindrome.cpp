// 题目本身很简单，统计数量就行，唯一需要注意的是奇数频次出现的字母，除了多余的一个，其他的也要用上，然后总的还需要加上一个可能存在的奇数

#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (auto c: s) {
          m[c] += 1;
        }
        int odd = 0;
        int even = 0;
        for (auto i: m) {
          if (i.second % 2 == 1) odd = 1;
          even += i.second / 2 * 2;
        }
        return even + odd;
    }
};


int main() {
  Solution s;
  int res = s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
  return 0;
}