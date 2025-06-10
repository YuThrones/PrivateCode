class RecentCounter {
public:
    queue<int> store;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!store.empty()) {
            if (store.front() + 3000 < t) {
                store.pop();
            }
            else {
                break;
            }
        }
        store.push(t);
        return store.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */