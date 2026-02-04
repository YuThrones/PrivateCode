class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        for (; i < arr.size();) {
            bool found = false;
            for (int j = 0; j < pieces.size(); ++j) {
                if (arr[i] == pieces[j][0]) {
                    // cout << i << " " << j << endl;
                    found = true;
                    for (int k = 0; k < pieces[j].size() && i + k < arr.size(); ++k) {
                        if (arr[i + k] != pieces[j][k]) {
                            return false;
                        }
                    }
                    i += pieces[j].size();
                }
                if (i >= arr.size()) {
                    return true;
                }
            }
            if (!found) {return false;}
        }
        return i >= arr.size();
    }
};


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        for(auto &p : pieces){
            mp[p[0]] = p;
        }
        int i = 0;
        int n = arr.size();
        while(i < n){
            if(mp.find(arr[i]) == mp.end()) return false;
            vector<int> &piece = mp[arr[i]];
            for(int num : piece){
                if(i >= n || arr[i] != num) return false;
                i++;
            }
        }
        return true;
    }
};