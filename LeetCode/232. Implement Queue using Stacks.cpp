// 跟之前用队列实现栈很像，注意用一个变量记录队列头，然后pop的时候使用两个栈来回倒一下就行

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int p = 0;
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
        if (s1.empty()) {
            p = x;
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int peek = s2.top();
        s2.pop();
        if (!s2.empty()) {
            p = s2.top();
        }
        else {
            p = 0;
        }
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return peek;
    }
    
    int peek() {
        return p;
    }
    
    bool empty() {
        return s1.empty();
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */