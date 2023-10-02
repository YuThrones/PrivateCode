// 原本是想着排序之后整理结果就行，先按身高降序，身高相同则按照前面人数升序，然后插入结果数组，但是速度不够快
// 看了下最佳答案，问题在插入这步是O(n)的复杂度，最佳答案用线段树来处理插入的问题，通过线段区间的和来表示要求前面人数的数量，把位置都算好了直接从尾部插入

class Solution {
public: 
    int ar[2001];  // 用于构建线段树的数组
    int st[8004];  // 线段树的数组

    // 构建线段树的函数
    void build(int idx, int ss, int se) {
        if(ss > se) return;  // 递归终止条件
        if(ss == se) {  // 如果是叶子节点
            st[idx] = ar[ss];  // 直接赋值
            return;
        }
        int mid = (ss + se) / 2;  // 计算中间位置
        build(idx * 2, ss, mid);  // 递归构建左子树
        build(idx * 2 + 1, mid + 1, se);  // 递归构建右子树
        st[idx] = st[2 * idx] + st[2 * idx + 1];  // 更新当前节点的值为左右子树之和
        return;
    }

    // 更新线段树节点的函数
    void update(int idx, int ss, int se, int pos, int val) {
        if(ss > se) return;  // 递归终止条件
        if(ss == se) {  // 如果是叶子节点
            st[idx] = val;  // 直接赋值
            return;
        }
        int mid = (ss + se) / 2;  // 计算中间位置
        if(pos <= mid) {  // 如果要更新的位置在左子树
            update(2 * idx, ss, mid, pos, val);  // 递归更新左子树
        } else {  // 如果要更新的位置在右子树
            update(2 * idx + 1, mid + 1, se, pos, val);  // 递归更新右子树
        }
        st[idx] = st[idx * 2] + st[2 * idx + 1];  // 更新当前节点的值为左右子树之和
        return;
    }

    // 查找满足条件的位置的函数
    int findpos(int idx, int ss, int se, int k) {
        if(st[idx] < k) return -1;  // 如果当前节点的值小于k，返回-1表示无解
        if(ss == se) {  // 如果是叶子节点
            return ss;  // 返回当前位置
        }
        int mid = (ss + se) / 2;  // 计算中间位置
        if(st[2 * idx] >= k) {  // 如果左子树的值大于等于k
            return findpos(2 * idx, ss, mid, k);  // 在左子树中查找
        }
        return findpos(2 * idx + 1, mid + 1, se, k - st[2 * idx]);  // 在右子树中查找
    }

    // 静态函数，用于排序规则
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] < b[0]) return true;
        if(a[0] == b[0]) return a[1] > b[1];
        return false;
    }

    // 主函数，重构队列的入口
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);  // 根据排序规则排序输入数组
        int n = v.size();  // 输入数组的大小
        for(int i = 1; i <= n; i++) {
            ar[i] = 1;  // 初始化数组，所有元素值为1
        }
        build(1, 1, n);  // 构建线段树

        vector<pair<int, int>> res;  // 用于保存最终结果的数组
        for(int i = 0; i < n; i++) {
            int k = v[i][1] + 1;  // 获取当前人前面需要有多少人
            int pos = findpos(1, 1, n, k);  // 在线段树中查找满足条件的位置
            update(1, 1, n, pos, 0);  // 更新线段树
            res.push_back({pos, i});  // 将满足条件的位置和当前人的索引加入结果数组
        }
        sort(res.begin(), res.end());  // 根据位置排序

        vector<vector<int>> ans;  // 用于保存最终答案的数组
        for(int i = 0; i < n; i++) {
            int id = res[i].second;  // 获取当前位置的人的原始索引
            ans.push_back({v[id][0], v[id][1]});  // 根据原始索引获取身高和前面的人数，加入答案数组
        }
        return ans;  // 返回答案数组
    }
};


#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先大后小，这样就不会后面插入的不会影响已有的
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res;
        for (const auto& p: people) {
            res.emplace(res.begin() + p[1], p);
        }
        return res;
    }

};

