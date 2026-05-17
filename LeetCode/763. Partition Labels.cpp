class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector <int> last(26, -1), ans;
        for(int i = 0; i < n; ++i){
            last[s[i] - 'a'] = i;
        }
        int end = -1, seg_len = 0;
        for(int i = 0; i < n; ++i){
            int let = s[i] - 'a';
            end = max(end, last[let]);
            seg_len++;
            if(end == i){
                ans.push_back(seg_len);
                seg_len = 0;
                end = -1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for(int i = 0; i < s.length(); ++i) {
            int n = s[i] - 'a';
            if (first[n] < 0) {
                first[n] = i;
            }
            last[n] = i;
        }
        for(int i = 0; i < s.length(); ++i) {
            int n = s[i] - 'a';
            if (i != first[n] || last[n] < 0) {
                continue;
            }
            int lastnum = last[n];
            for(int j = i; j < lastnum; ++j) {
                int nn = s[j] - 'a';
                if (last[nn] > lastnum) {
                    lastnum = last[nn];
                }
                first[nn] = -1;
                last[nn] = -1;
            }
            first[n] = -1;
            last[n] = -1;
            ans.push_back(lastnum - i + 1);
        }
        return ans;
    }
};