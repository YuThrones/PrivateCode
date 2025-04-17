最好答案因为没有重新生成一个vector<vector<int>> ，所以更快，只用了一个vector<int>保存上一行

class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
            vector<vector<int>> direction{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
            {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            vector<vector<int>> result;
            if (img.empty()) {return result;}
            if (img[0].empty()) {return result;}
            int r = img.size();
            int c = img[0].size();
            for (int row = 0; row < r; ++row) {
                result.push_back(vector<int>());
                for (int col = 0; col < c; ++col) {
                    int count = 1;
                    int sum = img[row][col];
                    for (auto dir : direction) {
                        int temp_row = row + dir[0];
                        int temp_col = col + dir[1];
                        if (temp_row < 0 || temp_col < 0 || temp_row >= r || temp_col >= c) {
                            continue;
                        }
                        sum += img[temp_row][temp_col];
                        ++count;
                    }
                    result[row].push_back(sum / count);
                }
            }
            return result;
        }
    };


    class Solution {
        public:
            vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
                int m = img.size();
                int n = img[0].size();
        
                vector<int> temp(n);
                int prevCorner = 0;
        
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        
                        int sum = 0;
                        int count = 0;
        
                        if (i + 1 < m) {
                            if (j - 1 >= 0) {
                                sum += img[i + 1][j - 1];
                                count += 1;
                            }
                            sum += img[i + 1][j];
                            count += 1;
                            if (j + 1 < n) {
                                sum += img[i + 1][j + 1];
                                count += 1;
                            }
                        }
        
                        if (j + 1 < n) {
                            sum += img[i][j + 1];
                            count += 1;
                        }
                        
                        sum += img[i][j];
                        count += 1;
        
                        if (j - 1 >= 0) {
                            sum += temp[j - 1];
                            count += 1;
                        }
        
                        if (i - 1 >= 0) {
                            if (j - 1 >=  0) {
                                sum += prevCorner;
                                count += 1;
                            }
                            
                            sum += temp[j];
                            count += 1;
        
                            if (j + 1 < n) {
                                sum += temp[j + 1];
                                count += 1;
                            }
                        }
        
                        if (i - 1 >= 0) {
                            prevCorner = temp[j];
                        }
        
                        temp[j] = img[i][j];
        
                        img[i][j] = sum / count;
                    }
                }
        
                return img;
            }
        };