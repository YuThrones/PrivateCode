// 这道题看着很简单，不过需要点灵感，是要用单调栈解决，往后往前遍历，维护一个单调小的栈，一旦遇到更大的就出栈，并且把出栈的数记录下来，就是可能得nums[k]
// 这样可以保证只要有一个数小于nums[k]且栈不为空，那就是能找到Nums[i]和nums[j]，复杂度O(n)

#include<vector>
#include<algorithm>
#include<stack>
using namespace std;



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        // stack<int> st;
        vector<int> st;
        int ak = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < ak) {
                return true;
            }
            while(!st.empty() && st.back() < nums[i]) {
                ak = st.back();
                st.pop_back();
            }
            st.emplace_back(nums[i]);
        }
        return false;
    }
};


int main() {
    Solution sol;
    vector<int> nums{3, 1, 4, 2};
    bool res = sol.find132pattern(nums);
    return 0;
}