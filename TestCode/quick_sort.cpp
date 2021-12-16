#include<iostream>
#include<random>

int RandIntRange(int range_min, int range_max) {
    // 返回前闭后开区间的随机数
    int res;
    res = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
    return res;
}

int* GenRandomArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand();
        // array[i] = RandIntRange(1, 101);
    }
    return array;
}

void PrintArray(int array[], int start, int end) {
    std::cout << "array:";
    for (int i = start; i < end; ++ i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Swap(int array[], int x, int y) {
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void Partition(int array[], int start, int end, int* res) {
    int left = start - 1;
    int right = end;
    int mid = RandIntRange(start, end);
    Swap(array, start, mid);
    int index = start;
    
    int part = array[start];
    while (index < right && left < right) {
        if (array[index] > part) {
            Swap(array, index, --right);
        }
        else if (array[index] < part) {
            Swap(array, index, ++left);
        }
        else {
            ++index;
        }
    }
    
    res[0] = left;
    res[1] = right;
}

void QuickSort(int array[], int start, int end) {
    if (start >= end) {
        return;
    }
    int* mid = new int[2];
    Partition(array, start, end, mid);
    QuickSort(array, start, mid[0] + 1);
    QuickSort(array, mid[1], end);
}

int main() {
    srand(time(NULL));
    int size = 10000;
    int* array = GenRandomArray(size);
    PrintArray(array, 0, size);
    QuickSort(array, 0, size);
    std::cout << "res ";
    PrintArray(array, 0, size);
    return 0;
}