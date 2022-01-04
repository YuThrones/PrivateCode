// 思路没什么好说的，堆或者优先队列搞定，花了点时间看api，但是运行速度居然很慢，有点难理解
// 看了下solution，问题出在pow我算了多次，没有预先计算存储
// 不过最快解法也不是使用priority_queue，而是用快排partition的方式来做
#include<queue>
#include<vector>
#include<iostream>
#include<random>
using namespace std;

bool operator <(vector<int> a, vector<int> b) {
    return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
}

struct cmp
{
    bool operator () (vector<int> a, vector<int> b) {
        return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
    }
};


// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         // priority_queue<vector<int>, vector<vector<int> >, less<vector<int>> > pq = priority_queue<vector<int>, vector<vector<int> >, less<vector<int>> >();
//         priority_queue<vector<int>, vector<vector<int> >, cmp> pq = priority_queue<vector<int>, vector<vector<int> >, cmp>();
//         vector<vector<int>> res = vector<vector<int>>();
//         for (int i = 0; i < points.size(); ++i) {
//             cout << "push " << points[i][0] << " " << points[i][1] << endl;
//             pq.push(points[i]);
//         }
//         for (int i = 0; i < k; ++i) {
//             cout << "pop " << pq.top()[0] << " " << pq.top()[1] << endl;

//             res.push_back(pq.top());
//             pq.pop();
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int mid = -1;
        int start = 0;
        int end = points.size();
        while(mid != k - 1) {
            mid = partition(points, start, end);
            if (mid > k - 1) {
                end = mid + 1;
            }
            else {
                start = mid;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int start, int end) {
        if (start >= end - 1) {
            return start;
        }
        int mid = start - 1;
        int index = start;
        int random_index = rand() % (end - start) + start;
        swap(points[start], points[random_index]);
        int random_dis = powDistance(points[start]);
        while(index < end) {
            if (powDistance(points[index]) <= random_dis) {
                swap(points[index], points[++mid]);
            }
            ++index;
        }
        return mid;
    }

    int powDistance(vector<int> p) {
        return pow(p[0], 2) + pow(p[1], 2);
    }
};

int main(){
    vector<vector<int>> in = vector<vector<int>>();
    int count = 100;
    vector<int> temp;
    // for (int i = 0; i < count; ++i) {
    //     temp = vector<int>();
    //     temp.push_back(i);
    //     temp.push_back(i);
    //     in.push_back(temp);
    // }
    temp = vector<int>();
    temp.push_back(6);
    temp.push_back(10);
    in.push_back(temp);
    temp = vector<int>();
    temp.push_back(-3);
    temp.push_back(3);
    in.push_back(temp);
    temp = vector<int>();
    temp.push_back(-2);
    temp.push_back(5);
    in.push_back(temp);
    temp = vector<int>();
    temp.push_back(0);
    temp.push_back(2);
    in.push_back(temp);

    Solution s = Solution();
    vector<vector<int>> out = s.kClosest(in, 1);
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i][0] << " " << out[i][1] << endl;
    }
    return 0;
}