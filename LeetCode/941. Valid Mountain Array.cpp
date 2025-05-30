class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        bool bIsIncrease = true;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i - 1]) {return false;}
            if (bIsIncrease) {
                if (arr[i] < arr[i - 1]) {
                    bIsIncrease = false;
                }
            }
            else {
                if (arr[i] > arr[i - 1]) {
                    return false;
                }
            }
        }

        return  true;
    }
};