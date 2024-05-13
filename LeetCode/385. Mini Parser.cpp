#include <string>
#include <stack>
#include <vector>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class Solution {
public:
    int end;
    NestedInteger deserialize(string s) {
        NestedInteger res;
        if (s.length() == 0) return res;
        end = -1;
        return s[0] == '[' ? handle(s, 1, true) : handle(s, 0, false);
    }

    NestedInteger handle(string& s, int start, bool isLst) {
        NestedInteger res;
        if (s.length() == 0) return res;
        int brancket = 0;
        int numIndex = -1;
        vector<NestedInteger> lst;
        for (int i = start; i < s.length(); ++i) {
            if (s[i] == '[') {
                lst.push_back(handle(s, i + 1, true));
                i = end;
            }
            else if (s[i] == ',')
            {
                if (numIndex != -1) {
                    NestedInteger temp;
                    temp.setInteger(stoi(s.substr(numIndex, i - numIndex)));
                    lst.push_back(temp);
                    numIndex = -1;
                }
            }
            else if (s[i] == ']') {
                end = i;
                break;
            }
            else if (numIndex == -1) {
                numIndex = i;
            }
        }
        if (numIndex != -1) {
            NestedInteger temp;
            temp.setInteger(stoi(s.substr(numIndex, s.length() - numIndex)));
            lst.push_back(temp);
            numIndex = -1;
        }
        if (!isLst) return lst[0];
        for (int i = 0; i < lst.size(); ++i) {
            res.add(lst[i]);
        }
        return res;
    }
};

int main() {
    string s = "[123,[456,[789]]]";
    Solution sol;
    auto res = sol.deserialize(s);
    return 0;
}