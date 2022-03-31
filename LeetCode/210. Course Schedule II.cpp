// 拿207题的答案改一下，搜索的时候每次把标志为可以使用的都记录下来即可
// 最快答案也差不多这个思路，只是数据不通过函数传递，用类变量记录

class Solution {
public:
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node, vector<int> &res)
    {
        dfsvis[node]=1;
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,vis,dfsvis,it, res))
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node]=0;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n+1];
        vector<int> res;
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
                if(dfs(adj,vis,dfsvis,i,res))
                {
                    vector<int> newRes;
                    return newRes;
                }
            }
        }
        return res;
        
    }
};