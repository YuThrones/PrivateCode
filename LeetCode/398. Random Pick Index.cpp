class Solution {
    public:
        map<int, vector<int>> count;
        Solution(vector<int>& nums) {    
            for (int i = 0; i < nums.size(); ++i) {
                if (count.find(nums[i]) == count.end()) {
                    count[nums[i]] = vector<int>();
                }
                count[nums[i]].push_back(i);
            }
        }
        
        int pick(int target) {
            int random_index = std::rand() % count[target].size();
            return count[target][random_index];
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * int param_1 = obj->pick(target);
     */

     class Solution {
        public:
            vector<int>nums;
            Solution(vector<int>& v) {
                nums=v;
            }
            
            int pick(int target) {
                int index=-1;
                while(1){
                    index=rand();
                    index%=nums.size();
                    if(nums[index]==target){
                        return index;
                    }
                }
                return -1;
            }
        };
        
        /**
         * Your Solution object will be instantiated and called as such:
         * Solution* obj = new Solution(nums);
         * int param_1 = obj->pick(target);
         */