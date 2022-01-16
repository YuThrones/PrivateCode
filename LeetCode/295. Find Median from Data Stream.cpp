// 标准可以双堆解的问题，一个最大堆维持较小的一半，一个较小堆维持较大的一半，平均分让两堆的数量差不超过1，如果size不同则返回较大堆，否则返回两个堆顶平均数
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > heap1;
    priority_queue<int, vector<int>, less<int> > heap2;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (heap1.empty() || heap1.top() < num) {
            heap1.push(num);
        }
        else {
            heap2.push(num);
        }
        
    }

    void balance() {
        while (heap1.size() > heap2.size() + 1) {
            heap2.push(heap1.top());
            heap1.pop();
        }
        while (heap2.size() > heap1.size() + 1) {
            heap1.push(heap2.top());
            heap2.pop();
        }
    }
    
    double findMedian() {
        balance();
        if (heap1.size() == heap2.size()) {
            return ((double)heap1.top() + (double)heap2.top()) / 2;
        }
        else if (heap1.size() > heap2.size()) {
            return (double)heap1.top();
        }
        else if (heap1.size() < heap2.size()) {
            return (double)heap2.top();
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */