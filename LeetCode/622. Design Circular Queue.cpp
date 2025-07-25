class MyCircularQueue {
public:
    vector<int> queue;
    int head = 0;
    int size = 0;
    int count = 0;

    MyCircularQueue(int k) {
        queue.resize(k, 0);
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[(head + count) % size] = value;
        ++count;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % size;
        --count;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(head + count - 1) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */