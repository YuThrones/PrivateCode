// 想到了用单调栈，对比最佳答案常数完全一致，可能一些if判断有一点点时间差别

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < 2; i++) {
            for (int i = n - 1; i >= 0; i--) {
                int nge = -1;
                while (!st.empty()) {
                    int top = st.top();
                    if (nums[i] < top) {
                        nge = top;
                        break;
                    } else {
                        st.pop();
                    }
                }
                ans[i] = nge;
                st.push(nums[i]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int>result (size, -1);
        stack<int> st;
        for (int i = size - 1; i >= 0; --i) {
            while(!st.empty() && st.top() < nums[i]) {
                st.pop();
            }
            if (st.empty() || st.top() > nums[i]) {
                st.push(nums[i]);
            }
        }

        for (int i = size - 1; i >= 0; --i) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty() && st.top() > nums[i]) {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }

        return result;
    }
};