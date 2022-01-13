// 经典固定长度堆解决的问题，最大的数放堆顶，只有数量不足或者比堆顶小才放入，返回堆顶即可

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int> > pq = priority_queue<int, vector<int>, less<int> >();
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                }
                else if (pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};