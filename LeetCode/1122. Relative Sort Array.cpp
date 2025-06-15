// 最快方式不是排序，是直接统计数量然后赋值，不过差距也是常数差距

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        vector<int> ans;
        for (auto i : arr1) {
            mp[i]++;
        }

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < mp[arr2[i]]; j++) {
                ans.push_back(arr2[i]);
            }
            mp[arr2[i]] = 0;
        }

        for (auto i : mp) {
            if (i.second != 0) {
                for (int j = 0; j < i.second; j++) {
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> record;
        for (int i = 0; i < arr2.size(); ++i) {
            record[arr2[i]] = i;
        }
        for (int i = 0; i < arr1.size(); ++i) {
            if (record.find(arr1[i]) == record.end()) {
                record[arr1[i]] = INT_MAX;
            }
        }
        sort(arr1.begin(), arr1.end(), [&record](int a, int b) {
            if (a == b) {
                return true;
            }
            if (record[a] != record[b]) {
                return record[a] < record[b];
            }
            return a < b;
        });
        return arr1;
    }
};