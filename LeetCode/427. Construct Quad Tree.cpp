// 这道题思路应该都是一样的，按照题目的要求先检查是否值完全一样，然后四分就行，写完就通过了，我看了下跟最快答案有一点点速度差距，但是在一个数量接
// 应该是因为编程细节，最佳答案的子函数是直接生成树，没有返回，其次是直接按照正方形处理，传参更少

#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    bool allSame(vector<vector<int>>& grid, int startX, int startY, int endX, int endY) {
        int firstVal = grid[startX][startY];
        for (int x = startX; x <= endX; ++x) {
            for (int y = startY; y <= endY; ++y) {
                if (grid[x][y] != firstVal) return false;
            }
        }
        return true;
    }

    Node* split(vector<vector<int>>& grid, int startX, int startY, int endX, int endY) {
        Node* res;
        if (startX > endX || startY > endY) {
            return res;
        }
        if (startX == endX && startY == endY) {
            res = new Node(grid[startX][startY], true);
            return res;
        }
        if (allSame(grid, startX, startY, endX, endY)) {
            res = new Node(grid[startX][startY], true);
            return res;
        }
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        res = new Node(true, false);
        res->topLeft = split(grid, startX, startY, midX, midY);
        res->topRight = split(grid, startX, midY + 1, midX, endY);
        res->bottomLeft = split(grid, midX + 1, startY, endX, midY);
        res->bottomRight = split(grid, midX + 1, midY + 1, endX, endY);
        return res;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node* res;
        int rowSize = grid.size();
        if (!rowSize) return res;
        int colSize = grid[0].size();
        if (!colSize) return res;
        res = split(grid, 0, 0, rowSize - 1, colSize - 1);
        return res;
    }
};

int main() {
    // vector<vector<int>> grid = {{0,1},{1,0}};
    vector<vector<int>> grid = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    Solution sol;
    sol.construct(grid);
    return 0;
}