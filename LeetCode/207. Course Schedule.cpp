// 用两个map分别记录某个值作为其他值的条件，以及其他值需要的条件
// 然后把所有没有需要条件的值置为true，其他置为false
// 从所有为true的值开始，尝试推导其他false的值，直到队列里面没有可以用来推导的值
// 如果这时候还没有值的条件没有被处理，说明存在循环，答案为false
// 看了下答案的最优解，是用深度优先搜索的方式找每个节点的前置条件是否存在环，速度要快一倍

#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int> > infer_set;
        unordered_map<int, set<int> > cond_set;
        vector<bool> used(numCourses, true);
        queue<int> check;

        for (auto v: prerequisites) {
            used[v[0]] = false;
            if (infer_set.find(v[1]) == infer_set.end()) {
                infer_set[v[1]] = set<int>();
            }
            infer_set[v[1]].insert(v[0]);
            
            if (cond_set.find(v[0]) == cond_set.end()) {
                cond_set[v[0]] = set<int>();
            }
            cond_set[v[0]].insert(v[1]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (used[i]) {
                check.push(i);
            }
        }
        
        while(!check.empty()) {
            int temp = check.front();
            check.pop();
            if (infer_set.find(temp) == infer_set.end()) {
                continue;
            }

            for (auto next:infer_set[temp]) {
                if (cond_set.find(next) != cond_set.end() && cond_set[next].find(temp) != cond_set[next].end()) {
                    cond_set[next].erase(temp);
                    if (cond_set[next].empty()) {
                        cond_set.erase(next);
                        used[next] = true;
                        check.push(next);
                    }
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!used[i]) {
                return false;
            }
        }

        return true;
    }
};


vector<int> make_vector(int a, int b) {
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    return res;
}


int main()
{
    int numCourses = 1;
    vector<vector<int>> prerequisites;
    prerequisites.push_back(make_vector(1, 0));
    // prerequisites.push_back(make_vector(0, 1));
    Solution s = Solution();
    cout << s.canFinish(numCourses, prerequisites) << endl;
    return 0;
}


class Solution {
public:
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node)
    {
        dfsvis[node]=1;
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,vis,dfsvis,it))
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node]=0;
        return false;
            
        
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n+1];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
            // adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> vis(n+1,0);
        vector<int> dfsvis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,dfsvis,i))
                    return false;
            }
        }
        return true;
        
    }
};