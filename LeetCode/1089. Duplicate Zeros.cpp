// 直接双循环能过，但是有重复挪动的浪费。
// 最佳答案是先算出一共有多少个0，要挪动多少位，然后从最后面开始排位置

class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                A[j] = A[i];
            if (A[i] == 0 && --j < n)
                A[j] = 0;
        }
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while(i < arr.size()) {
            if(arr[i] == 0) {
                for(int j = arr.size() - 1; j > i; --j) {
                    arr[j] = arr[j - 1];
                }
                i = i + 2;
            }
            else {
                ++i;
            }
        }
    }
};