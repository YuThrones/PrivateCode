// 经典双栈，一个存back的记录一个存forward的记录，back的top就是当前页面
// 更快的加法是不用栈，自己维护数组，不过感觉好像不是考察点？
#include<stack>
#include<string>
using namespace std;


class BrowserHistory {
public:
    stack<string> s1;
    stack<string> s2;
    BrowserHistory(string homepage) {
        s1 = stack<string>();
        s2 = stack<string>();
        s1.push(homepage);
    }
    
    void visit(string url) {
        s1.push(url);
        while(!s2.empty()) {
            s2.pop();
        }
    }
    
    string back(int steps) {
        while(s1.size() > 1 && steps > 0) {
            s2.push(s1.top());
            s1.pop();
            --steps;
        }
        return s1.top();
    }
    
    string forward(int steps) {
        while(s2.size() > 0 && steps > 0) {
            s1.push(s2.top());
            s2.pop();
            --steps;
        }
        return s1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */



class BrowserHistory {
public:
    vector<string> array;
    int index;
    int size;
    BrowserHistory(string homepage) {
        array.push_back(homepage);
        index = 0;
        size = 1;
    }
    
    void visit(string url) {
        ++index;
        size = index + 1;
        if (size > array.size()) {
            array.push_back(url);
        }
        else {
            array[index] = url;
        }
        
    }
    
    string back(int steps) {
        index -= steps;
        index = max(0, index);
        return array[index];
    }
    
    string forward(int steps) {
        index += steps;
        if (index > size - 1) {
            index = size - 1;
        }
        return array[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
