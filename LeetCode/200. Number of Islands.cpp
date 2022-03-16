// 最简单版本就是遇到某个点是1之后把这个点改为非1，然后用一个队列对周围的各自进行广度优先遍历，全部处理完之后就是一个岛，然后遍历剩下的位置
// 更进一步的方法则是利用并查集，不过在这道题并不会更快，只是可以使用多线程的方式加速

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    res += 1;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    // cout << "check" << i << " " << j << endl;
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        int f = p.first;
                        int s = p.second;
                        if (grid[f][s] == '1') {
                            grid[f][s] = '2';
                            // cout << "pop" << f << " " << s << endl;
                            if (f > 0) {
                                q.push(make_pair(f - 1, s));
                            }
                            if (f < grid.size() - 1) {
                                q.push(make_pair(f + 1, s));
                            }
                            
                            if (s > 0) {
                                q.push(make_pair(f, s - 1));
                            }
                            
                            if (s < grid[i].size() - 1) {
                                q.push(make_pair(f, s + 1));
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};