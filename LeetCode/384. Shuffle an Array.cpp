class Solution {
public:
    vector<int>* myNums;
    Solution(vector<int>& nums) {
        myNums = new vector<int>(nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return vector<int>(myNums->begin(), myNums->end());
    }
    
    vector<int> shuffle() {
        vector<int> res(myNums->begin(), myNums->end());
        for (int i = myNums->size(); i > 0; --i) {
            int index = rand() % i;
            swap(res[index], res[i - 1]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */