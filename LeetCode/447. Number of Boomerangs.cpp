// 这道题的核心其实就是预处理，先把每个点和其他点之间的距离先全部算出来，然后再找相同距离的点的数量，根据这个数量用排列组合的公式可以得出结果

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size ();
        
        vector <vector <int>> dis (n, vector <int> (n, 0));
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                int dist = distinct (points, i, j);
                dis [i][j] = dist;
                dis [j][i] = dist;
            }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector <int>& len = dis[i];
            sort (len.begin (), len.end ());
            int last = len [0], count = 1;
            for (int j = 1; j < len.size (); j++)
            {
                if (len [j] == last)
                    count++;
                else
                {
                    res += count * (count - 1);
                    count = 1;
                    last = len [j];
                }
            }
            res += count * (count - 1);
        }
        return res;
    }
    int distinct (vector<vector<int>>& points, int i, int j)
    {
        vector<int>& a = points[i];
        vector<int>& b = points[j];
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
};

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if (points.size() < 3) return 0;
        int res = 0;
        for (auto &point1: points) {
            unordered_map<long long, long long> dMap;
            for (auto &point2: points) {
                if (point1 == point2) continue;
                ++dMap[pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2)];
            }
            for (auto &it: dMap) {
                res += (it.second) * (it.second - 1);
            }
        }
        return res;
    }
};