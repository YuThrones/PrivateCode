class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.length();) {
            if (command[i] == 'G') {
                ans.push_back('G');
                ++i;
            }
            else {
                if (command[i + 1] == ')') {
                    ans.push_back('o');
                    i += 2;
                }
                else{
                    ans.append("al");
                    i += 4;
                }
            }
        }
        return ans;
    }
};