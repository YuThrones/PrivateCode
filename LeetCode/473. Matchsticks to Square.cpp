// 我本以为只需要每个边分别满足平均下来的长度即可，后面发现不对，因为有些边的形成情况会影响后续的生成，所以要整体考虑，如果一个边OK其他边不行是需要回退的
// 再配合同样的数字失败之后剪枝加速来解决问题

class Solution {
public:

    vector<int> matchsticks;
    vector<bool> st;

    bool dfs(int start, int cur, int len, int cnt){ //起始点，当前长度，每条边需要长度，完成的边数量
        if(cnt == 3) return true;
        if(cur == len) return dfs(0, 0, len, cnt + 1);

        for(int i = start; i < matchsticks.size(); i ++){
            if(st[i]) continue;
            if(cur + matchsticks[i] <= len){
                st[i] = true;
                if(dfs(i + 1, cur + matchsticks[i], len, cnt)) return true;
                st[i] = false;
            }

            if(!cur || cur + matchsticks[i] == len) return false;

            while(i + 1 < matchsticks.size() && matchsticks[i] == matchsticks[i+1]) i ++;//嫡长子继承剪枝
        }
        return false;
    }


    bool makesquare(vector<int>& matchsticks) {
        this->matchsticks = matchsticks;
        st = vector<bool>(matchsticks.size());

        int sum = 0;
        for(auto x : matchsticks) sum += x;
        if(sum % 4) return false;
        sum /= 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0, 0, sum, 0);
    }
};


#include<vector>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) {
            return false;
        }
        
        sort(matchsticks.begin(), matchsticks.end());
        unordered_set<int> used;
        for (int i = 0; i < 4; ++i) {
            if (!yu(matchsticks, used, total / 4, matchsticks.size() - 1)) {
                return false;
            }
        }
        return true;
    }
    
    bool yu(vector<int>& matchsticks, unordered_set<int>& used, int target, int end) {
        // cout << target << " " << end << endl;
        if (target < 0) return false;
        if (target == 0) return true;
        if (end < 0) return false;

        for (int i = end; i >= 0; --i) {
            if (used.find(i) == used.end() && matchsticks[i] <= target) {
                used.insert(i);
                if (yu(matchsticks, used, target - matchsticks[i], i - 1)) {
                    return true;
                }
                used.erase(i);
            }
        }
        
        return false;
    } 
    
    
};

int main() {
    Solution solution;
    // vector<int> input{3,3,3,3,4};
    // vector<int> input{1,1,1,1,1,1,1,1,1,1,1,1,1,1,102};
    vector<int> input{13,11,1,8,6,7,8,8,6,7,8,9,8};
    solution.makesquare(input);
    return 0;
}