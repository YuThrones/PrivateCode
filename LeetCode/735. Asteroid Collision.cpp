// 这道题也是栈的思路，每次新的行星数据和栈顶作比较，如果方向相同或者空栈则直接加入
// 否则看看栈顶和新行星哪个大，新行星小直接下一个
// 如果新行星较大就把栈顶去了，下一个循环比较新的栈顶

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans = vector<int> ();
        for (int i = 0; i < asteroids.size(); ++i) {
            while (true)
            {
                if (ans.empty() || !(ans[ans.size() - 1] > 0 && asteroids[i] < 0)) {
                    // cout << "push1 " << asteroids[i] << endl;
                    ans.push_back(asteroids[i]);
                    break;
                }
                if (abs(ans[ans.size() - 1]) > abs(asteroids[i])) {
                    // cout << "break1" << endl;
                    break;
                }
                else if (abs(ans[ans.size() - 1]) == abs(asteroids[i])) {
                    // cout << "pop1 " << asteroids[i] << endl;
                    ans.pop_back();
                    break;
                }
                else {
                    // cout << "pop2 " << asteroids[i] << endl;
                    ans.pop_back();
                }
            }
            
        }
        return ans;
    }
};