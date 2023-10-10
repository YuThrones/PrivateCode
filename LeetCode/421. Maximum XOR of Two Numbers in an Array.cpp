// 这道题的思路是，从vector中存在的最高位1开始，每次尝试在已有答案的基础上，把当前位设置为1，看看能不能在vector中找到可以异或出来的数
// 如果可以，那就是目前的最好答案，有点难想，感觉不止是medium

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0;
        int mask=0;
        unordered_set<int> s;
        if(nums.size()==1)
            return 0;
        int msb = log2(*max_element(nums.begin(),nums.end()));
        for(int i=msb;i>=0;i--){
            mask|=(1<<i);
            int temp = res | (1<<i);
            for(int num:nums){
                num&=mask;
                if(s.count(temp^num)){
                    res=temp;
                    break;
                }
                s.insert(num);
            }
            s.clear();
        }
        return res;
    }


};

int main() {
    vector<int> input({3,10,5,25,2,8});
    Solution s;
    int res = s.findMaximumXOR(input);
    return 0;
}