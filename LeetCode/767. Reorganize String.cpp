// 思路比较不明显，先统计词频，然后按照词频入大根堆，每次拿堆顶，并且不与前面一个相同附加到答案，如果堆拿空了还有剩余的词，说明不合法，返回空字符串
// 看了下最快方法，在这个思路上进行了额外优化，直接拿一个频次最大的隔一个位置直接插满，然后再拿第二大的继续，第一遍完了之后从第1个位置开始再操作一遍
struct cmp {
    bool operator ()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for (int i = 0; i < s.length(); ++i) {
            m[s[i]] += 1;
        }
        priority_queue<pair<char, int>, vector<pair<char, int> >, cmp> pq;
        for (auto it: m) {
            pq.push(make_pair(it.first, it.second));
        }
        string res = "";
        pair<char, int> flag = make_pair('\0', 0);
        pair<char, int> last = flag;
        pair<char, int> cur = flag;
        while(!pq.empty()) {
            cur = pq.top();
            pq.pop();
            cur.second -= 1;
            res += cur.first;
            if (last != flag) {
                pq.push(last);
                last = flag;
            }
            if (cur.second > 0) {
                last = cur;
            }
        }
        if (last != flag) {
            return "";
        }
        return res;
    }
};