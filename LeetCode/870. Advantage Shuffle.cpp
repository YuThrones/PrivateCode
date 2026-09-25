class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, -1);
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> n2;
        for(int i = 0; i < n; ++i) {
            n2.push_back({nums2[i], i});
        }
        sort(n2.begin(), n2.end());
        int end = n - 1;
        int start = 0;
        while(start <= end) {
            for(int i = n - 1; i >= 0; --i) {
                if(n2[i].first < nums1[end]) {
                    ans[n2[i].second] = nums1[end];
                    --end;
                }
                else {
                    ans[n2[i].second] = nums1[start];
                    ++start;
                }
            }
        }
        return ans;
    }
};