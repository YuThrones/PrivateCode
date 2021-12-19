// 这道题关键就是把数字的拼接顺序排好，所以只需要找到一个合适的比较规则就可以
// 这里使用的是x+y 拼接之后，大于y+x，数学上是可以证明这个比较具有传递性，只要用这个作为compare函数排序之后，就可以保证按顺序拼接之后一定是对的

bool comp(string x, string y) {
    return x + y > y + x;
}

bool comp_int(int x, int y) {
    return comp(to_string(x), to_string(y));
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), comp_int);
        for (int i = 0; i < nums.size(); ++i) {
            if ((res == "") && (nums[i] == 0) && (i != nums.size() - 1)) {
                continue;
            }
            res += to_string(nums[i]);
        }
        return res;
    }
};