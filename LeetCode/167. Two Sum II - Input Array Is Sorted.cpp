class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); ++i) {
            m[numbers[i]] = i;
        }
        
        for (int i = 0; i < numbers.size(); ++i) {
            int temp = target - numbers[i];
            
            if (temp < numbers[i]) {
                break;
            }
            
            if (m[temp]) {
                res.push_back(i + 1);
                res.push_back(m[temp] + 1);
                break;
            }
            m[numbers[i]] = i;
        }
        
        return res;
    }
};