// 比较经典的并查集的题目，主要还是考察并查集的实现

class Solution {
public:
    unordered_map<int, int> root;
    unordered_map<int, int> size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (vector<int>& e : edges) {
            if(findRoot(e[0]) != -1 && findRoot(e[1]) != -1 && findRoot(e[0]) == findRoot(e[1])) {
                return e;
            }
            add(e[0]);
            add(e[1]);
            merge(e[0], e[1]);

        }
        return {};
    }

    int findRoot(int node) {
        if(root.find(node) == root.end()) {
            return -1;
        }
        if (root[node] != node) {
            root[node] = findRoot(root[node]);
        }
        return root[node];
    }

    void merge(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);
        if(root1 == root2) {
            return;
        }
        if(size[root1] > size[root2]) {
            root[root2] = root1;
            size[root1] += size[root2];
        }
        else {
            root[root1] = root2;
            size[root2] += size[root1];
        }
    } 

    void add(int node) {
        if(findRoot(node) == -1) {
            // cout << "add " << node << endl;
            root[node] = node;
            size[node] = 1;
        }
    }
};