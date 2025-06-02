// 最佳答案更加简洁，也更快，主要是常数时间优势，先根据奇偶性直接确定起始点坐标，然后直接算就行，好像我想复杂了
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        for (int d = 0; d < m + n - 1; ++d) {
            int r, c;

            // Determine starting point of diagonal
            if (d % 2 == 0) {
                r = (d < m) ? d : m - 1;
                c = d - r;
                while (r >= 0 && c < n) {
                    result.push_back(mat[r][c]);
                    --r;
                    ++c;
                }
            } else {
                c = (d < n) ? d : n - 1;
                r = d - c;
                while (c >= 0 && r < m) {
                    result.push_back(mat[r][c]);
                    ++r;
                    --c;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int xsize = mat.size();
        if (!xsize) {return vector<int>();}
        int ysize = mat[0].size();
        if (!ysize) {return vector<int>();}

        int totalSize = xsize * ysize;
        vector<int> result (totalSize, 0);
        int x = 0;
        int y = 0;
        int dir = -1;
        bool bRow = true;
        int index = 0;
        while(index < totalSize) {
            result[index] = mat[x][y];
            ++index;
            int tempx, tempy;
            tempx = x + dir;
            tempy = y - dir;
            // cout << mat[x][y] << endl;
            // cout << index<< " "<< tempx << " " << tempy << endl;
            if (tempx < 0) {
                if (tempy < ysize) {
                    tempx = 0;
                }
                else {
                    tempx = x - dir;
                    tempy = y;
                }
                dir = -dir;
            }
            else if(tempy < 0) {
                if (tempx < xsize) {
                    tempy = 0;
                }
                else {
                    tempx = x;
                    tempy = y + dir;
                }
                dir = -dir;
            }
            else if (tempx >= xsize) {
                tempx = x;
                tempy = y + dir;
                dir = -dir;
            }
            else if (tempy >= ysize) {
                tempx = x - dir;
                tempy = y;
                dir = -dir;
            }
            x = tempx;
            y = tempy;
        }
        return result;
    }
};