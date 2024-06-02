// 这道题使用Dijkstra算法解
// 用自己写的反向索引堆可以加速

#include<vector>
#include<limits.h>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;

template<typename K, typename V, typename Compare = less<V>>
class MyHeap {
public:
    MyHeap() {
        size = 0;
        comp = Compare();
    }

    V top() {
        return valueMap[heap[0]];
    }

    bool contains(K key) {
        return valueMap.find(key) != valueMap.end();
    }

    V getValue(K key) {
        return valueMap[key];
    }

    void upsert(K key, V value) {
        if (indexMap.find(key) == indexMap.end()) {
            heap.push_back(key);
            indexMap[key] = size++;
        }
        valueMap[key] = value;
        topToBottom(indexMap[key]);
        bottomToTop(indexMap[key]);
    }

    void pop() {
        doSwap(0, size - 1);
        valueMap.erase(heap[size - 1]);
        indexMap.erase(heap[size - 1]);
        --size;
        heap.pop_back();
        topToBottom(0);
    }

    bool empty() {
        return size == 0;
    }

private:
    int size;
    vector<K> heap;
    unordered_map<K, V> valueMap;
    unordered_map<K, int> indexMap;
    Compare comp;

    void topToBottom(int pos) {
        if (pos >= size - 1) return;
        
        int pos1 = pos * 2 + 1;
        int pos2 = pos * 2 + 2;
        int tempPos = pos1;
        if (pos2 < size && comp(valueMap[heap[pos1]], valueMap[heap[pos2]])) {
            tempPos = pos2;
        }

        if (tempPos < size && comp(valueMap[heap[pos]], valueMap[heap[tempPos]])) {
            doSwap(pos, tempPos);
            topToBottom(tempPos);
        }
    }

    void bottomToTop(int pos) {
        if (pos == 0) return;
        if (pos >= size) return;

        int parent = (pos - 1) / 2;
        if (comp(valueMap[heap[parent]], valueMap[heap[pos]])) {
            doSwap(pos, parent);
            bottomToTop(parent);
        }
    }

    void doSwap(int pos1, int pos2) {
        K k1 = heap[pos1];
        K k2 = heap[pos2];
        indexMap[k2] = pos1;
        indexMap[k1] = pos2;
        swap(heap[pos1], heap[pos2]);
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph;
        vector<int> distance(n + 1);
        vector<bool> visited(n + 1);
        for (int i = 0; i <= n; ++i) {
            distance[i] = INT_MAX;
            visited[i] = false;
            graph.push_back(vector<pair<int, int>>());
        }
        for (auto& edge: times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        MyHeap<int, pair<int, int>, greater<pair<int, int>>> pq;
        pq.upsert(k, {0, k});
        distance[k] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            if (visited[node]) continue;
            visited[node] = true;
            for (auto& to: graph[node]) {
                if (!visited[to.first]) {
                    if (to.second + distance[node] < distance[to.first]) {
                        pq.upsert(to.first, {to.second + distance[node], to.first});
                        distance[to.first] = to.second + distance[node];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    int ans = sol.networkDelayTime(times, n, k);
    return 0;
}