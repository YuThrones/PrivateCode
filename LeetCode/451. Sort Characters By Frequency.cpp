// 第一反应是统计频率然后排序，虽然过了，但是看了别人答案发下我犯蠢了，统计频率之后直接大根堆按照字母数量构造就行，排序根本多余的

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> map;
        for(char ch : s) {
            map[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto pair: map){
            pq.push({pair.second, pair.first});
        }
        string ans;
        pair<int, char> cur;
        while(!pq.empty()){
            cur = pq.top();
            pq.pop();
            ans.append(cur.first, cur.second);
        }
        return ans;
    }
};

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    string frequencySort(string s) {
        vector<int> record(200, 0);
        vector<char> sList;
        for (auto &c: s) {
            record[c] += 1;
            sList.push_back(c);
        }
        sort(sList.begin(), sList.end(), [&record](char a, char b) {
            if (record[a] == record[b]) return a > b;
            return record[a] > record[b];
        });
        return string(sList.begin(), sList.end());
    }
};


int main() {
    Solution sol;
    string res = sol.frequencySort("tree");
    return 0;
}