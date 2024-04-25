#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    // 定义小顶堆，元素为 <sum, <index1, index2>>
    auto cmp = [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> minHeap(cmp);

    // 初始化堆，将第一个数组中的每个元素与第二个数组中的第一个元素的和以及这两个元素的索引放入堆中
    for (int i = 0; i < min(k, (int)nums1.size()); ++i) {
        minHeap.push({nums1[i] + nums2[0], {i, 0}});
    }

    vector<vector<int>> result;
    // 不断从堆中取出元素，将该数对的和与第二个数组中的下一个元素相加，放入堆中
    while (k-- > 0 && !minHeap.empty()) {
        auto [sum, indices] = minHeap.top();
        minHeap.pop();
        int i = indices.first;
        int j = indices.second;
        result.push_back({nums1[i], nums2[j]});
        if (j + 1 < nums2.size()) {
            minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
    }

    return result;
}
};


int main() {
    return 0;
}