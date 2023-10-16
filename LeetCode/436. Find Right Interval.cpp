// 我的想法是排序，然后直接二分搜第一个大于等于的就行，复杂度是O(nlogn)
// 最佳答案则是分别根据start和end排序，然后从前往后两个队列分别往后退，直到所有end都找到答案，复杂度一致，但是因为他排序两次之后不需要再搜索，常数更优


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts, ends;
        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back({intervals[i][0], i});
            ends.push_back({intervals[i][1], i});
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> res(intervals.size());        
        int i = 0, j = 0;
        while (i < starts.size() && j < ends.size()) {
            if (starts[i].first >= ends[j].first) {
                res[ends[j].second] = starts[i].second;
                j++;
            } else {
                i++;
            }        
        }
        while (j < ends.size()) {
            res[ends[j].second] = -1;
            j++;
        }
        return res;
    }
};

#include <vector>
#include <algorithm>
using namespace std;

bool compareVectors(const vector<int>& a, const vector<int>& b) {
    // 在这里定义自定义的比较规则
    return a[0] < b[0]; // 以每个向量的第一个元素为比较标准
}


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> search{intervals[i][1], intervals[i][1], intervals[i][1]};
            auto findRes = lower_bound(intervals.begin(), intervals.end(), search, compareVectors);
            if (findRes == intervals.end()) {
                res[intervals[i][2]] = -1;
            }
            else {
                res[intervals[i][2]] = (*findRes)[2];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> intervals = {{1,4},{2,3},{3,4}};
    vector<vector<int>> intervals = {{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};
    sol.findRightInterval(intervals);
    return 0;
}