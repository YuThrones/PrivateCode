// 最佳答案挺巧妙的，不是枚举每个移动方式对比，而是遍历所有为1的点，问两个点要重合需要怎么移动，然后给这个移动方式投一票。
// 这个方法很有意思，在密集矩阵，比如都是1的时候没区别，但是在稀疏矩阵加速非常多。

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int translation = 0, ans = 0, n = img1.size();
        vector<pair<int,int>> ones1, ones2;

        for (int i = 0; i < img1.size(); i++){
            for (int j = 0; j < img1[0].size(); j++){
                if (img1[i][j]) ones1.push_back({i, j});
                if (img2[i][j]) ones2.push_back({i, j});
            }
        }

        vector<vector<int>> frequency(2 * n - 1, vector<int>(2 * n - 1, 0));

        for (auto& [r, c] : ones1){
            for (auto& [r1, c1] : ones2){
                int dr = (r1 - r + n - 1), dc = (c1 - c + n - 1);
                ans = max(ans, ++frequency[dr][dc]);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i = -n + 1; i < n; ++i) {
            for(int j = -n + 1; j < n; ++j) {
                ans = max(ans, cal(img1, img2, i, j));
            }
        }
        return ans;
    }

    int cal(vector<vector<int>>& img1, vector<vector<int>>& img2, int right, int down) {
        int ans = 0;
        int n = img1.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int row = i + down; 
                int col = j + right;
                if (row >= 0 && row < n && col >= 0 && col < n && img1[row][col] == 1 && img2[i][j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};