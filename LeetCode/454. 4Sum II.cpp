// 这道题很容易想到将第一个和第二个求和合并成一个数组，第三个第四个合并，这样复杂度就是O(n*n)，
// 记录下12的和的每个数字出线的次数，然后乘以34的和对应的负数出线次数就行
// 最快答案是用算好的vector替换我使用的unordered_map，肯定是要更快一些，甚至还512对齐加快查找速度


auto init = []()
{ ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        const unsigned G = 512;
        const auto [min1, max1] = minmax_element(nums1.cbegin(), nums1.cend());
        const auto [min2, max2] = minmax_element(nums2.cbegin(), nums2.cend());
        const auto [min3, max3] = minmax_element(nums3.cbegin(), nums3.cend());
        const auto [min4, max4] = minmax_element(nums4.cbegin(), nums4.cend());
        if (min({*min1, *min2, *min3, *min4}) > 0 || max({*max1, *max2, *max3, *max4}) < 0)
            return 0;
        const int lb = min(*min1 + *min2, -*max3 - *max4);
        const int hb = max(*max1 + *max2, -*min3 - *min4);
        static vector<unsigned short> counts;
        const int csize = ((hb - lb + 1) + G - 1) / G * G;
        if (counts.size() < csize) {
            counts.clear();
            counts.resize(csize);
        } else {
            fill(counts.begin(), counts.begin() + csize, 0);
        }
        for (auto n1 : nums1) for(auto n2 : nums2) {
            const auto idx = n1 + n2 - lb;
            counts[idx]++;
        }
        int r = 0;
        for (auto n3 : nums3) for(auto n4 : nums4) {
            const auto idx = -n3 - n4 - lb;
            r += counts[idx];
        }
        return r;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (auto& n1: nums1) {
            for (auto& n2: nums2) {
                ++m1[n1 + n2];
            }
        }
        for (auto& n1: nums3) {
            for (auto& n2: nums4) {
                ++m2[n1 + n2];
            }
        }
        int res = 0;
        for (auto& p1: m1) {
            if (m2[-p1.first]) {
                res += p1.second * m2[-p1.first];
            }
        }
        return res;
    }
};