class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    makeunion(i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            // cout << i << parent[i] << endl;
            if(parent[i] == i) {
                ++ans;
            }
        }
        return ans;
    }

    int find(int x) {
        int root = x;
        while(parent[root] != root) {
            root = parent[root];
        }
        while(parent[x] != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    void makeunion(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) {
            return;
        }
        if (size[rootx] < size[rooty]) {
            swap(rootx, rooty);
        }

        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    }
};