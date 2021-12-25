// 这道题是在普通栈的基础上再加多一个返回最小值的功能，可以使用两个vector来做，第一个用来维持普通stack的功能，第二个则维护一个栈顶为最小值的单调栈
// 原理是如果一个后加入的数比先加入的数要大，那么他永远不存在成为最小值的可能，因为在最小值被pop之前他已经被pop，所以只需要维护一个最小值的单调栈即可O(1)复杂度返回最小值。
#include<vector>
using namespace std;
class MinStack {
public:
    vector<int> s1;
    vector<vector<int> > s2;
    MinStack() {
        s1 = vector<int>();
        s2 = vector<vector<int> >();
    }
    
    void push(int val) {
        s1.push_back(val);
        if (s2.empty() || s2[s2.size() - 1][0] > val) {
            s2.push_back(vector<int>());
            s2[s2.size() - 1].push_back(val);
        }
        else if (s2[s2.size() - 1][0] == val) {
            s2[s2.size() - 1].push_back(val);
        }
    }
    
    void pop() {
        if (s1.empty()) {
            return;
        }
        int val = s1[s1.size() - 1];
        s1.pop_back();
        if (s2.empty()) {
            return;
        }
        if (s2[s2.size() - 1][0] == val) {
            s2[s2.size() - 1].pop_back();
        }
        if (s2[s2.size() - 1].size() == 0) {
            s2.pop_back();
        }
    }
    
    int top() {
        return s1[s1.size() - 1];
    }
    
    int getMin() {
        if (s2.empty()) {
            return 0;
        }
        return s2[s2.size() - 1][0];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */