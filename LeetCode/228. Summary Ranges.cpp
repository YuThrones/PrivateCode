// 比较简单，记录下起始位置和上个位置，在超过范围的时候判断下范围是否大于1即可
// 唯一需要注意的就是数值溢出

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0];
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (check(nums[i], last)) {
                string temp = "";
                temp += to_string(start);
                if (last != start) {
                    temp += "->";
                    temp += to_string(last);
                }
                res.push_back(temp);
                start = nums[i];
            }
            last = nums[i];
        }
        
        string temp = "";
        temp += to_string(start);
        if (last != start) {
            temp += "->";
            temp += to_string(last);
        }
        res.push_back(temp);
        
        return res;
    }
    
    bool check(int a, int b) {
        if (a > 0) return a - 1 > b;
        else return a > b + 1;
    }
};