#include<vector>
#include<iostream>
using namespace std;

class MyCircularDeque {
public:
    vector<int> queue;
    int head;
    int tail;
    int size;
    int count = 0;
    MyCircularDeque(int k) {
        head = 0;
        tail = 1;
        size = k;
        count = 0;
        queue.resize(k);
    }
    
    bool insertFront(int value) {
        if(isFull()) {return false;}
        queue[head] = value;
        // mod之前不加size过不了
        head = (size + head - 1) % size;
        ++count;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {return false;}
        queue[tail % size] = value;
        tail = (size + tail + 1) % size;
        ++count;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {return false;}
        --count;
        head = (size + head + 1) % size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {return false;}
        --count;
        tail = (size + tail - 1) % size;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {return -1;}
        return queue[(size + head + 1) % size];
    }
    
    int getRear() {
        if(isEmpty()) {return -1;}
        return queue[(size + tail - 1) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    MyCircularDeque deque = MyCircularDeque(3);
    deque.insertLast(1);
    deque.insertLast(2);
    deque.insertFront(3);
    deque.insertFront(4);
    cout << deque.getRear() << endl;
    cout << deque.isFull() << endl;
    cout << deque.deleteLast() << endl;
    cout << deque.insertFront(4) << endl;
    cout << deque.getFront() << endl;
    return 0;
}