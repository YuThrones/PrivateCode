// 暴力算法就能过，不过存储的数据太多了，用单调栈加快查询就是最佳答案

class StockSpanner {
public:
    vector<int> store;
    StockSpanner() {
        store.clear();
    }
    
    int next(int price) {
        int ans = 0;
        for(int i = store.size() - 1; i >= 0; i--) {
            if (store[i] <= price) {
                ++ans;
            }
            else {
                break;
            }
        }
        store.push_back(price);
        return ans + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// 最佳答案，用单调栈加快查询
class StockSpanner {
public:
    stack<pair<int, int>> st; // (price, span)
    
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};