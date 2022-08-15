// 这道题一眼贪心，从最高分数开始处理，每次给相邻的比自己小的加1，全部处理完之后答案就出来了，但是和最快速度差距很大，看了下最快速度居然是带记忆的递归，有点奇怪，因为我的复杂度也是n2，能想到的可能就是有预处理什么，有常数时间差距

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        vector<vector<int>> record;
        vector<pair<int, int>> pos;

        for (int i = 0; i < matrix.size(); ++i) {
            record.push_back(vector<int>());
            for (int j = 0; j < matrix[0].size(); ++j) {
                record[i].push_back(0);
                pos.push_back(make_pair(i, j));
            }
        }
        
        sort(pos.begin(), pos.end(), 
             [&](pair<int, int>& a, pair<int, int>& b) {
                return matrix[a.first][a.second] > matrix[b.first][b.second];
            }
        );
        
        int ans = 0;
        
        for (int i = 0; i < pos.size(); ++i) {
            // 从数字最高的位置开始贪心处理附近比自己小的
            for (int j = 0; j < 4; ++j) {
                int near_x = pos[i].first + dir[j][0];
                int near_y = pos[i].second + dir[j][1];
                if (near_x >= 0 && near_x < matrix.size() && near_y >= 0 && near_y < matrix[0].size() && matrix[near_x][near_y] < matrix[pos[i].first][pos[i].second]) {
                    record[near_x][near_y] = max(record[near_x][near_y], record[pos[i].first][pos[i].second] + 1);
                    // cout << near_x << " " << near_y << " " << record[near_x][near_y] << endl;
                    ans = max(ans, record[near_x][near_y]);
                }
            }
        }
        
        return ans + 1;
    }
};