# 思路比较简单记录以矩阵[0, 0]为左上角，以目前位置[i, j]为右下角的矩形的面积，然后计算特定矩形的时候，就以这个面积，减去三个小矩形即可
# 最快答案思路大体没差，只是用了数组来存储，数量级一致，感觉没啥必要

class NumMatrix {
public:
    vector<vector<int>> store;
    NumMatrix(vector<vector<int>>& matrix) {
        int temp = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            temp = 0;
            store.push_back(vector<int>());
            for (int j = 0; j < matrix[0].size(); ++j) {
                temp += matrix[i][j];
                store[i].push_back(temp);
                if (i > 0) {
                    store[i][j] += store[i - 1][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = store[row2][col2];
        if(row1 > 0 && col1 > 0) {
            res += store[row1 - 1][col1 - 1];
        }
        if (row1 > 0) {
            res -= store[row1 - 1][col2];
        }
        if (col1 > 0) {
            res -= store[row2][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */