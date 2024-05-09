// 这道题用一个最小堆维持10个tweet可以解决，看了下最快答案，只用一个vector，我想了下如果出现tweet数据很多的情况速度应该不行

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

const int GetNum = 10;

class Twitter {
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (tweets.find(userId) == tweets.end()) {
            tweets[userId] = vector<pair<int, int>>();
        }
        tweets[userId].push_back({tweetId, ++cnt});
    }
    
    vector<int> getNewsFeed(int userId) {
        follow(userId, userId);
        vector<int> res;

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto uid: followMap[userId]) {
            int start = max(0, (int)tweets[uid].size() - GetNum);
            for (int i = 0; i < min(GetNum, (int)tweets[uid].size()); ++i) {
                if (pq.size() < GetNum || tweets[uid][start + i].second > pq.top().second) {
                    pq.push(tweets[uid][start + i]);
                    if (pq.size() > GetNum) pq.pop();
                }
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return vector<int>(res.rbegin(), res.rend());
    }
    
    void follow(int followerId, int followeeId) {
        if (followMap.find(followerId) == followMap.end()) {
            followMap[followerId] = unordered_set<int>();
        }
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap.find(followerId) == followMap.end()) {
            return;
        }
        followMap[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int cnt;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


int main() {
    Twitter tw;
    tw.postTweet(1, 5);
    tw.getNewsFeed(1);
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    tw.getNewsFeed(1);
    tw.unfollow(1, 2);
    tw.getNewsFeed(1);
}