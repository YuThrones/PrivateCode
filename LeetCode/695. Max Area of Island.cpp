// 这道题好像没有用并查集的必要，直接dfs更快

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxIsland = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    maxIsland = max(maxIsland, dfs(grid, r, c));
                }
            }
        }

        return maxIsland;        
    }

private:
    int dfs(vector<vector<int>>& grid,  int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c)
                 + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
};



class UnionSet {
    public:
    unordered_map<int, int> parent;
    unordered_map<int, int> num;
    int getRoot(int key) {
        if (parent[key] == key) {
            return parent[key];
        }
        parent[key] = getRoot(parent[key]);
        return parent[key];
    }

    void merge(int a, int b) {
        int rootA = getRoot(a);
        int rootB = getRoot(b);
        if (rootA == rootB) {return;}
        if (num[rootA] > num[rootB]) {
            parent[rootB] = rootA;
            num[rootA] += num[rootB];
        }
        else {
            parent[rootA] = rootB;
            num[rootB] += num[rootA];
        }
    }

    void add(int key) {
        if (parent.find(key) != parent.end()) {return;}
        parent[key] = key;
        num[key] = 1;
    }

    int getMax() {
        int ans = 0;
        for(auto& it : num) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {return 0;}
        int n = grid[0].size();
        if (n == 0) {return 0;}

        UnionSet USet;

        vector<vector<int>> dir {
             {1, 0}, {0, 1}
        };
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {continue;}

                int key = n * i + j;
                USet.add(key);

                for(auto& d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != 0) {
                        int Nkey = n * ni + nj;
                        USet.add(Nkey);
                        USet.merge(key, Nkey);
                    }
                }
            }
        }

        return USet.getMax();
    }
};