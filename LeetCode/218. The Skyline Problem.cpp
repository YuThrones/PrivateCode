// 我能想到的办法就是，根据位置，把左边界和右边界放一起排序
// 然后用一个堆维护一个位置的最大值，当最大值发生改变时说明有一个新的节点
// 虽然可以正常跑过，但是速度有点慢
// 看了下最快答案的解法，比较复杂，但是速度快很多，详细解析放在218copy里面

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;



template<typename T>
void Swap(T *array, int x, int y) {
    T temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

template<typename T>
class Heap
{
    private:
        /* data */
        T* array;
        int size;
        int capacity;
        bool (*cmp)(T, T);
        unordered_map<T, int> dict;

    public:

        Heap(/* args */);
        Heap(int max_size, bool (*cmp_func)(T, T)) {
            array = new T[max_size];
            capacity = max_size;
            size = 0;
            cmp = cmp_func;
        }
        ~Heap() {};

        void HeapUp(int index) {
            if (!CheckIndexValid(index)) {
                return;
            }
            while((index - 1) / 2 >= 0 && cmp(array[index], array[(index - 1) / 2])) {
                Swap(array, index, (index - 1) / 2);
                dict[array[index]] = index;
                dict[array[(index - 1) / 2]] = (index - 1) / 2;
                index = (index - 1) / 2;
            }
        }

        void HeapDown(int index) {
            if (!CheckIndexValid(index)) {
                return;
            }
            while(index * 2 + 1 < size) {
                int choose = array[index * 2 + 1];
                int choose_index = index * 2 + 1;
                if (index * 2 + 2 < size && cmp(array[index * 2 + 2], array[index * 2 + 1])) {
                    choose = array[index * 2 + 2];
                    choose_index = index * 2 + 2;
                }
                if (cmp(array[index], choose)) {
                    break;
                }
                Swap(array, index, choose_index);
                dict[array[index]] = index;
                dict[array[choose_index]] = choose_index;
                index = choose_index;
            }
        }

        bool HeapInsert(T value) {
            if (IsFull()) {
                return false;
            }
            array[size] = value;
            dict[array[size]] = size;
            HeapUp(size++);
            return true;
        }

        bool HeapRemove(T& value) {
            if (dict.find(value) == dict.end()) {
                return false;
            }
            int index = dict[value];
            Swap(array, index, --size);
            dict[array[index]] = index;
            dict.erase(array[size]);
            HeapUp(index);
            HeapDown(index);
            return true;
        }

        T Pop() {
            Swap(array, 0, --size);
            dict[array[0]] = 0;
            dict.erase(array[size]);
            HeapDown(0);
            return array[size];
        }

        T Top() {
            return array[0];
        }

        bool CheckIndexValid(int index) {
            return 0 <= index && index < size;
        }

        bool IsFull() {
            return size >= capacity;
        }

        bool IsEmpty() {
            return size <= 0;
        }

        void Print() {
            for (int i = 0; i < size; ++i) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        void Test(T x, T y) {
            cout <<"test"<< cmp << " "<< x << y << endl;
            cout << cmp(x, y) << endl; 
        }
};



bool cmp(vector<int> a, vector<int>b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }

    return a[2] > b[2];
}


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;

        vector<vector<int> > points;
        for (auto vi : buildings) {
            vector<int> temp1;
            temp1.push_back(vi[0]);
            temp1.push_back(vi[2]);
            temp1.push_back(1);
            vector<int> temp2;
            temp2.push_back(vi[1]);
            temp2.push_back(vi[2]);
            temp2.push_back(-1);
            points.push_back(temp1);
            points.push_back(temp2);
        }

        sort(points.begin(), points.end(), cmp);

        int lastIndex = -1;
        int lastValue = -1;

        unordered_map<int, int> dict;
        Heap<int> heap(points.size(), [](int a, int b) {return a > b;});

        for (auto point: points) {
            int curMax = 0;
            if (!heap.IsEmpty()) {
                curMax = heap.Top();
            }

            if (lastIndex != point[0] && (lastIndex != -1)) {
                // 到了下一个点，需要结算
                if (lastValue != curMax) {
                    vector<int> resTemp;
                    resTemp.push_back(lastIndex);
                    resTemp.push_back(curMax);
                    res.push_back(resTemp);
                }
                lastValue = curMax;
            }

            if (point[2] == 1) {
                if (!dict[point[1]]) {
                    heap.HeapInsert(point[1]);
                }
                dict[point[1]] += 1;
            }
            else {
                dict[point[1]] -= 1;
                if (!dict[point[1]]) {
                    heap.HeapRemove(point[1]);
                }
            }
            
            if (!heap.IsEmpty()) {
                curMax = heap.Top();
            }
            
            lastIndex = point[0];
        }

        vector<int> resTemp;
        resTemp.push_back(lastIndex);
        resTemp.push_back(0);
        res.push_back(resTemp);

        return res;
    }
};

int main() {
    const int row = 1;
    const int col = 3;

    // int input[row][col] = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    int input[row][col] = {{0,2147483647,2147483647}};
    vector<vector<int>> in;
    for (int i = 0; i < row; ++i) {
        in.push_back(vector<int>());
        for (int j = 0; j < col; ++j) {
            in[i].push_back(input[i][j]);
        }
    }
    Solution s = Solution();
    s.getSkyline(in);
    return 0;
}