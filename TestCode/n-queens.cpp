#include <chrono>
#include <iostream>
#include <vector>

// 最简单版本8皇后问题，可以统计路径，还可以优化
class Solution1 {
public:
    int getAns(int queens) {
        if (queens <= 0) return 0;
        std::vector<int> path;
        return solve(path, queens, 0);
    }

    int solve(std::vector<int>& path, int queens, int row) {
        if (row == queens) {
            // for (int i = 0; i < path.size(); ++i) {
            //     std::cout << path[i]  << " ";
            // }
            // std::cout << std::endl;
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < queens; ++i) {
            // 检查每个位置是否合格
            if (check(path, queens, row, i)) {
                path.push_back(i);
                ans += solve(path, queens, row + 1);
                path.pop_back();
            }
        }
        return ans;
    }

    bool check(std::vector<int>& path, int queens, int row, int col) {
        for (int i = 0; i < path.size(); ++i) {
            int preCol = path[i];
            if (preCol == col || abs(row - i) == abs(col - preCol)) return false;
        }
        return true;
    }
};


// 位运算版本8皇后问题，只能用来统计数量
class Solution2 {
public:
    int getAns(int queens) {
        if (queens <= 0) return 0;
        
        int limit = (1 << queens) - 1;
        return solve(limit, 0, 0, 0);
    }

    // col 是列的限制
    // left 是左上到右下对角线的限制
    // right 是右上到左下对角线的限制
    int solve(int limit, int col, int left, int right) {
        // 已经位置满了，完成要求
        if (limit == col) return 1;
        int candidate = ~(col | left | right) & limit;
        int ans = 0;
        while(candidate != 0) {
            int last = candidate & (-candidate);
            ans += solve(limit, col | last, (left | last) << 1, (right | last) >> 1);
            candidate ^= last;
        }
        return ans;
    }
};


int main() {
    int queens = 14;

    auto start = std::chrono::high_resolution_clock::now();
    Solution1 sol1;
    int ans1 = sol1.getAns(queens);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    std::cout << "Solution1 ans: " << ans1 << std::endl;
    std::cout << "Solution1 cost time: " << time.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    Solution2 sol2;
    int ans2 = sol2.getAns(queens);
    end = std::chrono::high_resolution_clock::now();
    time = end - start;
    std::cout << "Solution2 ans: " << ans2 << std::endl;
    std::cout << "Solution2 cost time: " << time.count() << std::endl;

    return 0;
}