// 自己想到的还是先生成再排序，但是比最快方法慢很多，人家是直接根据n确定每个位置要放什么数字，要抠的边界比较多

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for(int i = 0; i < n; i++)
        {
            res[i] = num;
            if(num*10 <= n)
            {
                num *= 10;
            }
            else
            {
                while(num + 1 > n || num % 10 == 9)//continuous 9s
                {
                    num /= 10;
                }
                num++;
            }
        }
        return res;
    }
};

#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        vector<pair<string, int>> data;
        for (int i = 1; i <= n; ++i) {
            data.push_back({to_string(i), i});
        }
        sort(data.begin(), data.end(), cmp);
        for (auto p: data) {
            res.push_back(p.second);
        }
        return res;
    }

    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        return a.first < b.first;
    }
};

int main() {
    return 0;
}