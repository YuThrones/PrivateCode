// 记录下每个值出现的数量，其中一个过半后break就行
// 看了下最快解法，有点经验，不用哈希表，而是用两个变量，一个count一个num，一个记录当前记录的数，一个是他出现的数量，如果遇到不一样的数字就减少
// 在确定必然存在解的情况，解必然可以覆盖其他所有数

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int s = nums.size();
        int half = (s + 1) / 2;
        for (int i = 0; i < s; ++i) {
            m[nums[i]] += 1;
            if (m[nums[i]] >= half) {
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int num =0;
        for(int n:nums){
             if(count==0){
                  num=n;
             }
            if(n==num)
                count++;
            else 
                count--;
        }
        return num;
    }
};