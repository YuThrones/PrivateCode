#include <vector>
#include <iostream>
using namespace std;

class SegTree{
public:
vector<int> myNum;
vector<int> data; // 一个节点代表的数值总和
vector<int> change; // 一个节点中所有区域的总修改量
vector<bool> flag; // 代表一个节点是否被赋值过
    SegTree(vector<int>& num) {
        myNum = num;
        data.resize(num.size() * 4, 0);
        change.resize(num.size() * 4, 0);
        flag.resize(num.size() * 4, false);
        build(0, num.size() - 1, 1);
    }

    void build(int start, int end, int node) {
        // 对闭区间[start, end]进行线段树构建，当前节点编号为node
        if (start == end) {
            data[node] = myNum[start];
            return;
        }

        int mid = start + ((end - start) >> 1);
        build(start, mid, node * 2);
        build(mid + 1, end, node * 2 + 1);
        data[node] = data[node * 2] + data[node * 2 + 1];
    }

    int getNum(int left, int right, int start, int end, int node) {
        // left和right为要查询的区域，start和end为当前检查区域，node为当前节点
        if (left <= start && end <= right) {
            return data[node];
        }

        pushDown(start, end, node);

        int mid = start + ((end - start) >> 1);
        int res = 0;
        if (mid >= left) res += getNum(left, right, start, mid, node * 2);
        if (mid < right) res += getNum(left, right, mid + 1, end, node * 2 + 1);
        return res;
    }

    void addNum(int left, int right, int value, int start, int end, int node) {
        // left和right为要增加的区域，start和end为当前增加区域，value为增加的值,node为当前节点
        // 注意如果left和right包括的区分大于1，是每一段都要加上value这个值
        if (left <= start && end <= right) {
            // 当前区间是目标区间子集，直接修改数据然后返回
            data[node] += (end - start + 1) * value;
            change[node] += value;
            return;
        }

        int mid = start + ((end - start) >> 1);

        pushDown(start, end, node);
        if (mid >= left) addNum(left, right, value, start, mid, node * 2);
        if (mid < right) addNum(left, right, value, mid + 1, end, node * 2 + 1);
        data[node] = data[node * 2] + data[node * 2 + 1];
    }

    void setNum(int left, int right, int value, int start, int end, int node) {
        // left和right为要设置的区域，start和end为当前区域，value为设置的值,node为当前节点
        if (left <= start && end <= right) {
            // 当前区间是目标区间子集，直接修改数据然后返回
            data[node] = (end - start + 1) * value;
            change[node] = value;
            flag[node] = true;
            return;
        }
        int mid = start + ((end - start) >> 1);

        pushDown(start, end, node);
        if (mid >= left) setNum(left, right, value, start, mid, node * 2);
        if (mid < right) setNum(left, right, value, mid + 1, end, node * 2 + 1);
        data[node] = data[node * 2] + data[node * 2 + 1];
    }

    void pushDown(int start, int end, int node) {
        if (start == end) return;
        int mid = (start + ((end - start) >> 1));
        if (change[node] && end != start) {
            // 当前节点有修改过，往下更新两个子节点
            if (flag[node]) {
                data[node * 2] = (mid - start + 1) * change[node];
                change[node * 2] = change[node];
                flag[node * 2] = true;
                data[node * 2 + 1] = (end - mid) * change[node];
                change[node * 2 + 1] = change[node];
                flag[node * 2 + 1] = true;
            }
            else {
                data[node * 2] += (mid - start + 1) * change[node];
                change[node * 2] += change[node];
                data[node * 2 + 1] += (end - mid) * change[node];
                change[node * 2 + 1] += change[node];
            }
            change[node] = 0;
            flag[node] = false;
        }
    }

    void print() {
        for (int i = 0; i < data.size(); ++i) {
            cout << i << " " << data[i] << " " << change[i] << " " << flag[i] << endl;
        }
    }
};


int main() {
    vector<int> input;
    const int count = 15;
    for (int i = 0; i < count; ++i) {
        input.push_back(i);
    }
    SegTree tree(input);
    tree.print();
    cout << "add" << endl;
    tree.setNum(1, 10, 1, 0, count - 1, 1);
    tree.setNum(8, 14, 2, 0, count - 1, 1);
    tree.setNum(5, 7, 3, 0, count - 1, 1);
    tree.print();

    cout << "check" << endl;
    for (int i = 0; i < count; ++i) {
        // for (int j = i; j < count; ++j) {
        //     cout << i << " " << j << " " << tree.getNum(i, j, 0, count - 1, 1) << endl;
        // }
        cout << i << " " << tree.getNum(i, i, 0, count - 1, 1) << endl;
    }
}