// 逻辑是很简单的，每次要拿栈顶的时候把queue1全部弹出放到queue2，并且视情况把最后一个弹出的值返回后根据top或者pop决定是否弹出

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if (empty()) {
            return 0;
        }
        int temp = 0;
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        temp = q1.front();
        q1.pop();
        swap();
        return temp;
    }
    
    int top() {
        if (empty()) {
            return 0;
        }
        int temp = 0;
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        temp = q1.front();
        q1.pop();
        q2.push(temp);
        swap();
        return temp;
    }

    void swap() {
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    bool empty() {
        return q1.size() == 0 and q2.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */