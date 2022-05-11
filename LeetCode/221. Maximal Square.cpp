// 自己写了个动态规划，发现还没有带记忆的递归快，原因在于有三层遍历，实际上递归可能不需要列举所有正方形
// 改进了一下，把长度的枚举去掉，只枚举右下方的位置能够正常通过，但是还不够快,再优化了判断顺序，得到了可以接受的结果

#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     vector<vector<vector<int>>> record;
    //     int row = matrix.size();
    //     if (row < 1) return 0;
    //     int col = matrix[0].size();
    //     if (col < 1) return 0;
    //     int maxLength = max(row, col);
        
    //     for(int i = 0; i < row; ++i) {
    //         record.push_back(vector<vector<int>>());
    //         for (int j = 0; j < col; ++j) {
    //             record[i].push_back(vector<int> (maxLength, 0));
    //         }
    //     }
        
    //     int res = 0;
        
    //     for(int i = 0; i < row; ++i) {
    //         for (int j = 0; j < col; ++j) {
    //             if (matrix[i][j] == '1') {
    //                 record[i][j][0] = 1;
    //                 res = 1;
    //             }
    //         }
    //     }
        
    //     for (int l = 1; l < maxLength; ++l) {
    //         for(int i = 0; i < row; ++i) {
    //             for (int j = 0; j < col; ++j) {
    //                 if (!record[i][j][l - 1]) continue;

    //                 if (i + l >= row) continue;
    //                 if (j + l >= col) continue;
    //                 if (matrix[i + l][j + l] != '1') continue;
    //                 if (!record[i + 1][j][l - 1]) continue;
    //                 if (!record[i][j + 1][l - 1]) continue;

    //                 record[i][j][l] = l + 1;
    //                 res = max(res, record[i][j][l]);
    //             }
    //         }
            
    //     }
        
    //     return res * res;
        
    // }
    

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> record;
        int row = matrix.size();
        if (row < 1) return 0;
        int col = matrix[0].size();
        if (col < 1) return 0;
        int maxLength = max(row, col);
        
        for(int i = 0; i < row; ++i) {
            record.push_back(vector<int>());
            for (int j = 0; j < col; ++j) {
                record[i].push_back(0);
            }
        }
        
        int res = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] != '1') continue;
                int temp = maxLength + 1;

                if (i - 1 < 0 || j - 1 < 0) temp = 0;
                else {
                    temp = min(temp, record[i - 1][j]);
                    temp = min(temp, record[i][j - 1]);
                    temp = min(temp, record[i - 1][j - 1]);
                }

                // if (i - 1 >= 0) temp = min(temp, record[i - 1][j]);
                // else temp = 0;
                // if (j - 1 >= 0) temp = min(temp, record[i][j - 1]);
                // else temp = 0;
                // if (i - 1 >= 0 && j - 1 >= 0) temp = min(temp, record[i - 1][j - 1]);
                // else temp = 0;
                record[i][j] = temp + 1;
                res = max(res, record[i][j]);
            }
        }
        
        return res * res;
        
    }
};

int main() {
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'1','0','1','0','0'});
    matrix.push_back(vector<char>{'1','0','1','1','1'});
    matrix.push_back(vector<char>{'1','1','1','1','1'});
    matrix.push_back(vector<char>{'1','0','0','1','0'});

    Solution s;
    cout << s.maximalSquare(matrix);
}