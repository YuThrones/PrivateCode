// 可以使用类似二分的思想，取矩形中心，然后划分为四个区域，进行递归
// 看了下最快的解法，比我快很多，方式是从右上角往走左，如果遇到比target大就往左走，遇到相同返回true，否则往下走，比起从左上角出发，好处是当遇到左边比target小时，只需要选择往下即可，不需要考虑往右的问题

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        if (!matrix[0].size()) return false;
        return search(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

    bool search(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return false;
        if (matrix[x1][y1] > target) return false;
        if (matrix[x2][y2] < target) return false;
        if (x1 == x2 && y1 == y2) return matrix[x1][y1] == target;
        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2;
        return search(matrix, target, x1, y1, mx, my)
            || search(matrix, target, mx + 1, y1, x2, my)
            || search(matrix, target, x1, my + 1, mx, y2)
            || search(matrix, target, mx + 1, my + 1, x2, y2);
    }
};
