class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        for (auto c :s) {
            if (stack.size() > 0) {
                if (stack.back() == c) {
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(c);
        }

        string ans;
        ans.reserve(stack.size());
        for(auto c : stack) {
            ans.push_back(c);
        }
        return ans;
    }
};