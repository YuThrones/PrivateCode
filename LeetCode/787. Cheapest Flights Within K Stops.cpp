// Bellman-Ford算法可以解，但是速度比我想象中的慢
// 最快答案是按层处理的BFS

#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int cur[n];
        int next[n];
        for (int i = 0; i < n; ++i) {
            cur[i] = INT_MAX;
        }
        cur[src] = 0;

        for (int i = 0; i <= k; ++i) {
            copy(cur, cur + n, next);
            for (auto& edge: flights) {
                if (cur[edge[0]] != INT_MAX) {
                    next[edge[1]] = min(next[edge[1]], cur[edge[0]] + edge[2]);
                    cout << edge[1] << " " << next[edge[1]] << endl;
                }
            }
            copy(next, next + n, cur);
        }
        return cur[dst] != INT_MAX ? cur[dst] : -1;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> flights {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3; 
    int k = 1;
    sol.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for ( auto& f : flights ) {
            adj[f[0]].push_back({f[1],f[2]});
        }
        int stops = 0;
        vector<int> cost(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        while( stops <= k && !q.empty() ) {
            for ( int i = q.size(); i > 0; i-- ) {
                auto [city, cur_cost] = q.front();
                q.pop();
                for ( auto& [next, price] : adj[city] ) {
                    if ( cur_cost + price >= cost[next] ) 
                        continue;
                    cost[next] = cur_cost + price;
                    q.push({next,cost[next]});
                }
            }
            stops++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
