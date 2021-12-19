// 感觉就是让我手写一下快排而已，但是写完发现其实只需要一次partition就可以了。。。
#include<random>
#include<random>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1;
        int right = nums.size();
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[0]);
                break;
            }
        }
        int key = nums[0];
        while(index < right && left < right) {
            if (nums[index] < key) {
                swap(nums[index], nums[++left]);
            }
            else if (nums[index] > key) {
                swap(nums[index], nums[--right]);
            } 
            else {
                ++index;
            }
        }
    }
    
    void Print(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size());
    }
    
    void quickSort(vector<int>& nums, int start, int end) {
        if (end - start <= 1) {
            return;
        }
        vector<int> mid = partition(nums, start, end);
        quickSort(nums, start, mid[0] + 1);
        quickSort(nums, mid[1], end);
    }
    
    vector<int> partition(vector<int>& nums, int start, int end) {
        vector<int>mid = vector<int>();
        int key_index = rand() % (start - end) + start;
        swap(nums[start], nums[key_index]);
        int key = nums[start];
        
        
        mid.push_back(start - 1);
        mid.push_back(end);
        int index = start;
        while(index < mid[1] && mid[0] < mid[1]) {
            if (nums[index] < key) {
                swap(nums[index], nums[++mid[0]]);
            }
            else if (nums[index] > key) {
                swap(nums[index], nums[--mid[1]]);
            } 
            else {
                ++index;
            }
        }
        return mid;
    }

    void Print(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};