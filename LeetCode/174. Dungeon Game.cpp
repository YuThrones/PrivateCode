// 动态规划问题，用一个矩阵存储每个各自需要的最小值，从右下角开始，往左上角填
// 每个位置只依赖自己右边和下边的各自，从中选出需求更小的那一个作为下一步
// 每个位置有两种情况，如果这个位置的值是负数，那么需要负担绝对值的代价，以及下一步的代价（注意如果是下一步代价最小为1，因为数值为0即为死亡）
// 如果这个位置的数是非负数，那么就要看看当前位置提供的值是否足以覆盖下一步的代价，如果足够，那就不需要付出额外代价，否则则对前一步剩下的值有要求，最小为1


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) {
            return 0;
        }
        if (dungeon[0].size() == 0) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        int record[row][col];

        
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                int temp = INT_MAX;
                if (i < row - 1) {
                    temp = min(temp, record[i + 1][j]);
                }
                if (j < col - 1) {
                    temp = min(temp, record[i][j + 1]);
                }
                
                if (temp == INT_MAX) {
                    temp = 1;
                }
                
                if (dungeon[i][j] >= 0) {
                    record[i][j] = max(temp - dungeon[i][j], 1);
                }
                else {
                    record[i][j] = -dungeon[i][j] + temp;    
                }
            }
        }
        
        // for (int i = 0; i < row; ++i) {
        //     for (int j = 0; j < col; ++j) {
        //         cout << record[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return record[0][0];
    }
};