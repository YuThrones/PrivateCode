// 本来想着有什么巧妙解法，但是没想到，看了下解析，其实就是数据量小，直接全排列，最多就是算出来之后打表

class Solution {
public:
    int countArrangement(int n) {
        vector<int> ans {0, 1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
        return ans[n];
    }
    // vector<int> arr;
    // int count = 0;
    // int countArrangement(int n) {
    //     arr.clear();
    //     count = 0;
    //     for (int i = 0; i <= n; ++i) {
    //         arr.push_back(0);
    //     }
    //     dfs(1, n);
    //     return count;
    // }
    // void dfs(int pos, int n) {
    //     if (pos > n) {
    //         ++count;
    //     }
    //     for (int i = 1; i <= n; ++i) {
    //         if (arr[i] == 0) {
    //             if (i % pos == 0 || pos % i == 0) {
    //                 arr[i] = 1;
    //                 dfs(pos + 1, n);
    //                 arr[i] = 0;
    //             }
    //         }
    //     }
    // }
};