#include<iostream>
#include<vector>
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
                index = choose_index;
            }
        }

        bool HeapInsert(T value) {
            if (IsFull()) {
                return false;
            }
            array[size] = value;
            HeapUp(size++);
            return true;
        }

        T Pop() {
            Swap(array, 0, --size);
            HeapDown(0);
            return array[size];
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


void HeapSort(vector<int>& list) {
    Heap<int> heap = Heap<int>(list.size(), [](int x, int y) -> bool {return x < y;});
    for (int i = 0; i < list.size(); ++i) {
        heap.HeapInsert(list[i]);
    }

    for (int i = 0; i < list.size(); ++i) {
        list[i] = heap.Pop();
    }
}

void Test() {
    vector<int> list = vector<int>();
    for (int i = 1000; i > 0; --i) {
        list.push_back(i);
    }
    HeapSort(list);
    for (int i = 0; i < 1000; ++i) {
        cout << list[i] << " ";
    }
}

int main() {
    Test();
    return 0;
}