// 拿207题的答案改一下，搜索的时候每次把标志为可以使用的都记录下来即可
// 最快答案也差不多这个思路，只是数据不通过函数传递，用类变量记录

// class Solution {
// public:
//     bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node, vector<int> &res)
//     {
//         dfsvis[node]=1;
//         vis[node]=1;
//         for(auto it: adj[node])
//         {
//             if(vis[it]==0)
//             {
//                 if(dfs(adj,vis,dfsvis,it, res))
//                     return true;
//             }
//             else if(dfsvis[it]==1)
//                 return true;
//         }
//         dfsvis[node]=0;
//         res.push_back(node);
//         return false;
//     }
//     vector<int> findOrder(int n, vector<vector<int>>& pre) {
//         vector<int> adj[n+1];
//         vector<int> res;
//         for(int i=0;i<pre.size();i++)
//         {
//             adj[pre[i][0]].push_back(pre[i][1]);
//             // adj[pre[i][1]].push_back(pre[i][0]);
//         }
//         vector<int> vis(n+1,0);
//         vector<int> dfsvis(n+1,0);
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i]==0)
//             {
//                 if(dfs(adj,vis,dfsvis,i,res))
//                 {
//                     vector<int> newRes;
//                     return newRes;
//                 }
//             }
//         }
//         return res;
        
//     }
// };

// 这部分是链式前向*算法完成的求解，是邻接矩阵和邻接表的折衷，稍微复杂一点，但是空间表现很优秀，也不需要动态申请空间
#include<vector>
using namespace std;

#define MAIN_MAX 2001

class Solution {
public:
    int head[MAIN_MAX];  // 这个节点的第一条出度边
    int next[MAIN_MAX * MAIN_MAX]; // 同个出度点每条边指向的下一条边
    int to[MAIN_MAX * MAIN_MAX]; // 每条边指向的入度点
    int indegree[MAIN_MAX]; // 每个点的入度数量
    int queue[MAIN_MAX]; // 处理拓扑排序时的队列
    int h, t; // 队列头尾节点
    int cnt; // 当前边的编号
    

    void init(int numCourses) {
        cnt = 1;
        h = t = 0;
        for (int i = 0; i < numCourses; ++i) {
            head[i] = 0;
            indegree[i] = 0;
        }
    }

    void addEdges(int nodeFrom, int nodeIn) {
        next[cnt] = head[nodeFrom];
        to[cnt] = nodeIn;
        ++indegree[nodeIn];
        head[nodeFrom] = cnt++;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses);
        
        // 用链式前向*算法 记录图的数据
        for (auto& p: prerequisites) {
            addEdges(p[1], p[0]);
        }

        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                queue[t++] = i;
            }
        }

        int firstNode;
        int edge;
        int nextNode;
        while(h < t) {
            firstNode = queue[h++];
            ans.push_back(firstNode);
            edge = head[firstNode];
            while(edge) {
                nextNode = to[edge];
                --indegree[nextNode];
                if (indegree[nextNode] == 0) {
                    queue[t++] = nextNode;
                }
                edge = next[edge];
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};
