// 遍历的时候存一下值对应的index，如果一个值对应的差值能找到直接返回这两个index就行

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); ++i) {
            int temp = target - numbers[i];
            if (m[temp]) {
                res.push_back(m[temp]);
                res.push_back(i + 1);
                break;
            }
            m[numbers[i]] = i + 1;
        }
        
        return res;
    }
};