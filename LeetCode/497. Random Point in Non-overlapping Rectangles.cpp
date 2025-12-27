// 这道题最佳答案跟我思路是一样的，只是我用的uniform_int_distribution进行随机，一开始错误的用面积公式来计算权重，但是因为是整数点，所以需要+1计算

class Solution {
public:
    vector<vector<int>> tangles;
    vector<int> prefix;
    int total = 0;
    Solution(vector<vector<int>>& rects) {
        for (int i = 0; i < rects.size(); i++)
        {
            tangles.push_back({rects[i][0], rects[i][1], rects[i][2], rects[i][3]});
            int area = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            total += area;
            prefix.push_back(total);
        }
    }
    
    vector<int> pick() {
        int r = rand() % total;
        int index = upper_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
        int min_x = tangles[index][0];
        int max_x = tangles[index][2];
        int min_y = tangles[index][1];
        int max_y = tangles[index][3];
        int x = rand() % (max_x - min_x + 1) + min_x;
        int y = rand() % (max_y - min_y + 1) + min_y;
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

class Solution {
public:
    vector<vector<int>> rects;
    vector<int> area;
    int totalWeight;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalWeight = 0;
        for (vector<int>& rect : rects) {
            // 这里需要注意因为是整数点，需要+1，跟面积公式不一样
            area.push_back((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
            totalWeight += area.back();
        }
    }
    
    vector<int> pick() {
        static std::mt19937 engine(
            std::chrono::system_clock::now().time_since_epoch().count()
        );

        std::uniform_int_distribution<int> dist(0, totalWeight - 1);

        int weight = dist(engine);

        for(int i = 0; i < area.size(); ++i) {
            if (weight < area[i]) {
                std::uniform_int_distribution<int> dist1(rects[i][0], rects[i][2]);
                std::uniform_int_distribution<int> dist2(rects[i][1], rects[i][3]);
                return {dist1(engine), dist2(engine)};
            }
            weight -= area[i];
        }
        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */