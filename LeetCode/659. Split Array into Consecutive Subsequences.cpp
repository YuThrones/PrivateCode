class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n = nums.size(), start = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] > 1)
            {
                if (!helper(nums, start, i - 1))
                    return false;

                start = i;
            }
        }

        return helper(nums, start, n - 1);
    }

    bool helper(vector<int>& nums, int start, int end)
    {
        int noOfNums = nums[end] - nums[start] + 1;
        vector<int> frequency(noOfNums);

        for (int i = start; i <= end; i++)
            frequency[nums[i] - nums[start]]++;

        vector<int> noOfSizeOne(noOfNums), noOfSizeTwo(noOfNums),
            noOfSubsequences(noOfNums);

        noOfSubsequences[0] = noOfSizeOne[0] = frequency[0];

        for (int i = 1; i < noOfNums; i++)
        {
            if (frequency[i] < noOfSizeOne[i - 1] + noOfSizeTwo[i - 1])
                return false;

            noOfSizeTwo[i] = noOfSizeOne[i - 1];

            noOfSizeOne[i] = max(0, frequency[i] - noOfSubsequences[i - 1]);

            noOfSubsequences[i] = frequency[i];
        }

        return noOfSizeTwo[noOfNums - 1] == 0 && noOfSizeOne[noOfNums - 1] == 0;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.empty()) {return false;}
        int maxNum = nums[nums.size() - 1];
        int minNum = nums[0];
        unordered_map<int, int> count;
        unordered_map<int, int> end;
        for(int n : nums) {
            ++count[n];
        }
        int i = minNum;
        for(int i : nums) {
            if(count[i] == 0) {
                continue;
            }
            while(count[i] > 0)
            {
                if(end[i - 1] > 0) {
                    --end[i - 1];
                    ++end[i];
                    --count[i];
                }
                else {
                    if(count[i + 1] > 0 && count[i + 2] > 0) {
                        --count[i];
                        --count[i + 1];
                        --count[i + 2];
                        ++end[i + 2];
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};