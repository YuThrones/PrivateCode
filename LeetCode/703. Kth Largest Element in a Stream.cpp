class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int limit = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (auto n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (min_heap.size() < limit) {
                min_heap.push(val);
            }
            else if (min_heap.top() < val) {
                min_heap.pop();
                min_heap.push(val);
            }
            return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */