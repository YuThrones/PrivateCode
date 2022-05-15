// 第一反应肯定是用map来做，但是很显然不是这么简单就能成为最优解，翻了下最佳答案，很巧妙
// 利用答案最多不超过2个，并且数量必然超过3分之一，采用了一旦不同就削减数量的方式，找到有可能超过三分之一的两个数，再第二次遍历，判断是否真的符合，O(n)复杂度

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        map<int, int> record;
        int limit = nums.size() / 3;
        for (auto n: nums) record[n] += 1;
        for (auto it: record) {
            if (it.second > limit) res.push_back(it.first);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
         int sz = nums.size();
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}
};