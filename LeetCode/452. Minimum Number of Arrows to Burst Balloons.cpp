// 这道题自己没想到，看了下gpt的思路，用贪心算法，先按结束位置升序排列，然后从第一个气球开始往后，看看他的结束位置可以戳破哪些气球，
// 当遇到第一个起始位置大于这个结束位置时，说明不得不增加一根新的箭了，注意结束位置相同，起始位置不一样的情况，顺序不影响结果，
// 因为下一个箭就是按相同的这个结束位置来，一定能处理所有这种情况
// 最佳答案把vector<int>变成了pair<int, int>，应该是为了加快排序，速度是一个数量级的，常数时间更快


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int endPoint = points[0][1];
        for (int i = 0; i < points.size(); ++i) {
            if (endPoint < points[i][0]) {
                endPoint = points[i][1];
                ++res;
            }
        }

        return res;
    }
};