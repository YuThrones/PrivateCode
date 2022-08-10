#include <iostream>
#include <algorithm>
using namespace std;

// 得到和offset平齐的当前位的数
int getValue(int limit, int offset) {
    return limit / offset % 10;
}

// 得到array中小于等于指定数字的最大值，如果不存在返回-1,存在则返回索引
int near(int array[], int length, int value) {
    if (length <= 0) {
        return -1;
    }
    if (array[0] > value) {
        return -1;
    }
    int start = 0;
    int end = length;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == value) {
            return mid;
        }
        else if (array[mid] > value) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return start - 1;
}

// 返回全部用给定value填充的，长度与offset平齐的数
int rest(int value, int offset) {
    int res = 0;
    while(offset > 0) {
        res = res * 10 + value;
        offset /= 10;
    }
    return res;
}

// 找到用array组成的比limit小的最大的数，而且位数必须与offset相同，当offset位数小于limit，说明前面都已经追平（否则会直接后面补齐最大的数）
// 找不到则返回-1
int process2(int array[], int length, int limit, int offset) {
    if (offset == 0) {
        // 走到这里来，说明前面都平齐了，那就是找到完美答案了，直接返回
        return limit;
    }

    int curValue = getValue(limit, offset);
    int nearIndex = near(array, length, curValue);
    if (nearIndex == -1) {
        // 找不到更小的数了，告诉前一位自己想办法处理
        return -1;
    }
    else if (array[nearIndex] < curValue) {
        // 找到的数比当前小，那么后面全部用最大值补
        return (limit / offset - curValue) * offset + array[nearIndex] * offset + rest(array[length - 1], offset / 10);
    }
    else {
        // 可以找到一样的数，那么递归找答案
        int res = process2(array, length, limit, offset / 10);
        if (res == -1) {
            // 走到这里，说明后面没法平齐，这里要找更小一位，然后后面都用最大值补齐
            if (nearIndex == 0) {
                // 当前位找不到更小的数了，还得找前面处理
                return -1;
            }
            return array[nearIndex - 1] * offset + rest(array[length - 1], offset / 10);
        }
        else {
            // 说明找到答案了，直接返回
            return res;
        }
    }
    return -1;
}


// 找到用array组成的比limit小的最大的数
int process(int array[], int length, int limit) {
    // 先给array排序
    sort(array, array + length);

    // limit-1之后直接算小于等于更加方便
    --limit;

    // 先让offset与limit平齐
    int offset = 1;
    while(offset <= limit / 10) {
        offset *= 10;
    }

    int res = process2(array, length, limit, offset);
    if (res == -1) {
        // 说明找不到位数相同的答案，位数减少一位用最大值拼即可
        if (offset == 1) {
            // 本来就只有一位，不满足就没答案了
            return res;
        }

        res = 0;
        while (offset > 1) {
            res = res * 10 + array[length - 1];
            offset /= 10;
        }
    }
    return res;
}

int main() {
    int limit = 123;
    int array[] = {3, 2, 5};
    for (int i = 0; i < limit; ++i) {
        cout << i << " " << process(array, 3, i) << endl;
    }
}