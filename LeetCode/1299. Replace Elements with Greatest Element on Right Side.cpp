class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int biggest = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = biggest;
            if (temp > biggest) {
                biggest = temp;
            }
        }
        return arr;
    }
};