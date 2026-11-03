// 思路比较简单，反过来思考就行，第一个肯定是最小的，然后递归把后面的算好，然后把后面部分最后一个提上来就解决了
// 但是不够快
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        return cal(deck, 0);
    }

    vector<int> cal(vector<int>& deck, int start) {
        if (start == deck.size()) {
            return {};
        }
        vector<int> ans = cal(deck, start + 1);
        vector<int> newAns;
        newAns.push_back(deck[start]);
        if (ans.size() > 0) {
            newAns.push_back(ans.back());
        }
        for(int i = 0; i + 1 < ans.size(); ++i) {
            newAns.push_back(ans[i]);
        }
        return newAns;
    }
};


// 最佳答案
// 使用递推替代递归，而且只用一个deque，避免了vector<int>反复创建插入
// 模仿只剩下一个最大的数，然后倒推
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>());
        deque<int>dq;
        for(int i =0;i<deck.size();i++){
            if(!dq.empty()){
                int last=dq.back();
                dq.pop_back();
                dq.push_front(last);
            }
            dq.push_front(deck[i]);
        }
        vector<int>ans(dq.begin(),dq.end());
        return ans;
    }
};