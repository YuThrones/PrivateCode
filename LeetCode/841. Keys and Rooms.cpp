class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlocked(n, false);
        queue<int> que;
        que.push(0);
        while(!que.empty()) {
            int top = que.front();
            que.pop();
            unlocked[top] = true;
            for(int r : rooms[top]) {
                if (!unlocked[r])
                {
                    que.push(r);
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if (!unlocked[i]) {return false;}
        }
        return true;
    }
};