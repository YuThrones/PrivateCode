// 简单的map记录就行，小优化就是把多余的删了
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] += 1;
            if (m[nums[i]] >= 3)
            {
                m.erase(m.find(nums[i]));
            }
        }
        return m.begin()->first;
    }
};