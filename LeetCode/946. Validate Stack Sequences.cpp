class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) {
            return false;
        }
        stack<int> st;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        while(i < n && j < n) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            else {
                st.push(pushed[i]);
                ++i;
            }
        }
        while(!st.empty() && st.top() == popped[j]) {
            st.pop();
            ++j;
        }
        return i == n && j == n;
    }
};