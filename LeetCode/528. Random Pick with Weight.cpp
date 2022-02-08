#include<vector>
#include<iostream>
#include<random>
#include<map>
using namespace std;

// 手写了一个二分找大于等于的第一个数，后来发现其实直接用lower_bound就可以了，不过结果是一样的

class Solution {
public:
    vector<int> accumulate;
    Solution(vector<int>& w) {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);        
        accumulate.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i) {
            accumulate.push_back(w[i]);
            accumulate[i] += accumulate[i - 1];
        }
    }
    
    int pickIndex() {
        int weight = rand() % accumulate[accumulate.size() - 1];
        int start = 0;
        int end = accumulate.size();
        int mid = 0;
        int ans = end - 1;
        while(start < end) {
            mid = (start + end) / 2;
            if (accumulate[mid] > weight)
            {
                if (mid - 1 < 0 || accumulate[mid - 1] <= weight)
                {
                    return mid;
                }
                else 
                {
                    end = mid;
                }
            }
            else if (accumulate[mid] == weight)
            {
                return mid + 1;
            }
            else {
                start = mid;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(14);
    v.push_back(1);
    v.push_back(7);
    map<int, int> m;
    Solution sol = Solution(v);
    for (int i = 0; i < 1000; ++i) {
        int res = sol.pickIndex();
        m[res] += 1;
    }

    for (auto it: m) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}