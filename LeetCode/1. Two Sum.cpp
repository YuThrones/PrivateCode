// 总体思路是从前往后遍历，在map里面查找是否存在和target的差值一样的数，是的话和当前的index一起返回，否则把自己的值和index作为pair插入到map中
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> index_map = map<int, int>();
            vector<int> res = vector<int>();
            for (int i = 0; i < nums.size(); ++i) {
                map<int, int>::iterator iter = index_map.find(target - nums[i]);
                if (iter != index_map.end()) {
                    res.push_back(iter->second);
                    res.push_back(i);
                }
                else {
                    index_map.insert(pair<int, int>(nums[i], i));
                }   
            }
            return res;
        }
    };