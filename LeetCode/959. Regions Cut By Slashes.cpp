class Solution {
public:
    vector<int> par;
    vector<int> cnt;

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0) {return 0;}
        par.clear();
        par.resize(m * n * 4, -1);
        for(int i = 0; i < par.size(); ++i) {
            par[i] = i;
        }
        cnt.clear();
        cnt.resize(m * n * 4, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int temp = (n * i + j) * 4;
                if(grid[i][j] == '/') {
                    makeUnion(temp, temp + 1);
                    makeUnion(temp + 2, temp + 3);
                }
                else if (grid[i][j] == '\\') {
                    makeUnion(temp, temp + 3);
                    makeUnion(temp + 1, temp + 2);
                }
                else {
                    makeUnion(temp, temp + 1);
                    makeUnion(temp + 1, temp + 2);
                    makeUnion(temp + 2, temp + 3);
                }
                if(i > 0) {
                    int up = (m * (i - 1) + j) * 4 + 2;
                    makeUnion(temp, up);
                }
                if (j > 0) {
                    int left = (m * i + (j - 1)) * 4 + 3;
                    makeUnion(temp + 1, left);
                }
                if (i < n - 1) {
                    int down = (m * (i + 1) + j) * 4;
                    makeUnion(temp + 2, down);
                }
                if (j < n - 1) {
                    int right = (m * i + j + 1) * 4 + 1;
                    makeUnion(temp + 3, right);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m * n * 4; ++i) {
            if (par[i] == i) {
                ++ans;
            }
        }
        return ans;
    }

    int getParent(int n) {
        if(par[n] == n || par[n] == -1) {
            return par[n];
        }
        par[n] = getParent(par[n]);
        return par[n];
    }

    int makeUnion(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if(pa == pb)  {
            return pa;
        }
        if(cnt[pa] > cnt[pb]) {
            par[pb] = pa;
            cnt[pa] += cnt[pb];
            return pa;
        }
        par[pa] = pb;
        cnt[pb] += cnt[pa];
        return pb;
    }
};