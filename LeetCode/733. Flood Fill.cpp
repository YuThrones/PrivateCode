class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int row = image.size();
            if (row == 0) {return image;}
            int col = image[0].size();
            if (col == 0) {return image;}
            int origin = image[sr][sc];
            if (origin == color) {return image;}
            stack<pair<int, int>> st;
            st.push({sr, sc});
            image[sr][sc] = color;
            vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            while(!st.empty()) {
                pair<int, int> temp = st.top();
                st.pop();
                for (auto it : dir) {
                    pair<int, int> adj = {temp.first + it.first, temp.second + it.second};
                    // cout << adj.first << " " << adj.second << endl;
                    if (adj.first < 0 || adj.first >= row 
                    || adj.second < 0 || adj.second >= col) {
                        continue;
                    }
                    if (image[adj.first][adj.second] == origin){
                        image[adj.first][adj.second] = color;
                        st.push(adj);
                    }
                }
            }
            return image;
        }
    };