// 这道题很有意思，把持有的钥匙数量作为额外的一个维度，跟横纵坐标一起记录状态
// 用BFS算法解，如果想到了这个想法，剩下就是coding问题了

#include<vector>
#include<string>
#include<tuple>
#include<memory.h>
using namespace std;

#define MAX_M 30
#define MAX_N 30
#define MAX_K 6 



class Solution {
public:
    // int distance[MAX_M][MAX_N][1 << MAX_K];
    bool visited[MAX_M][MAX_N][1 << MAX_K];
    tuple<int, int, int> queue[MAX_M * MAX_N * (1 << MAX_K)];
    int h, t;

    void build() {
        // memset(distance, 0x3f, sizeof(distance));
        memset(visited, false, sizeof(visited));
        h = t = 0;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int dir[]{-1, 0, 1, 0, -1};
        build();
        int m = grid.size();
        int n = grid[0].length();
        int key = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    key |= 1 << (grid[i][j] - 'a');
                }

                // 起始点
                if (grid[i][j] == '@') {
                    // distance[i][j][0] = 0;
                    queue[t++] = {i, j, 0};
                }
            }
        }

        int level = 1;
        int count = 1;
        while(h < t) {
            for (int j = 0; j < count; ++j)  {
                auto& top = queue[h++];
                int x = get<0>(top);
                int y = get<1>(top);
                int k = get<2>(top);

                if (visited[x][y][k]) continue;
                visited[x][y][k] = true;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];
                    int nk = k;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny][nk]) continue;

                    // 墙不能通过
                    if (grid[nx][ny] == '#') continue;

                    // 有锁但是没钥匙
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z' && (nk & 1 << (grid[nx][ny] - 'A')) == 0) {
                        continue;
                    }

                    // 有钥匙，捡起来
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                        nk |= 1 << (grid[nx][ny] - 'a');
                        if (nk == key) return level;
                        
                    }
                    queue[t++] = {nx, ny, nk};
                }
            }
            count = t - h;
            ++level;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    // vector<string> grid{"@.a..","###.#","b.A.B"};
    vector<string> grid{"@..aA","..B#.","....b"};
    int ans = sol.shortestPathAllKeys(grid);
    return 0;
}

#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstring>
#include <unordered_map>
using namespace std;
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
const int MAX_QUEUE = 1<<15;
const int MAX_N = 30;
const char ROAD = '.';
typedef unsigned long long ull;
struct QueueElement{
    int key,y,x,dist;
};
template<typename T>
class Queue{
public:
    Queue() : head(0),tail(0),size(0){}
    void push(T val){
        arr[tail] = val;
        tail = (tail+1)&(MAX_QUEUE-1);
        ++size;
    }
    void pop(){
        head = (head+1)&(MAX_QUEUE-1);
        --size;
    }
    T front() const {
        return arr[head];
    }
    bool empty() const{
        return size==0;
    }
private:
    T arr[MAX_QUEUE];
    int head,tail,size;
};
class Solution {
public:
    ull visited[30][30];
    int N,M;
    inline int getKeyNum(char ch) const{
        return ch - 'a';
    }
    inline int getWallNum(char ch) const{
        return ch - 'A';
    }
    inline bool checkLowerCase(char ch) const{
        return ch >= 'a' && ch <= 'z';
    }
    inline bool checkUpperCase(char ch) const{
        return ch>='A' && ch<='Z';
    }
    auto getStartPos(const vector<string>& grid) const {
        for(int y=0;y<N;++y){
            for(int x=0;x<M;++x){
                if(grid[y][x]=='@'){
                    return pair<int,int>(y,x);
                }
            }
        }
        return pair<int,int>(-1,-1);
    }
    int calcFullKey(const vector<string>& grid) const {
        int ret = 0;
        for(int y=0;y<N;++y){
            for(int x=0;x<M;++x){
                if(checkLowerCase(grid[y][x])){
                    ret|=(1<<getKeyNum(grid[y][x]));                    
                }
            }
        }
        return ret;
    }
    inline bool checkValid(int y,int x){
        return y>=0 && y<N && x>=0 && x<M;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        memset(visited,0,sizeof(visited));
        N = grid.size();M = grid[0].size();
        auto [startY,startX] = getStartPos(grid);
        grid[startY][startX] = '.';
        visited[startY][startX] = 1LL;
        Queue<QueueElement> q;
        q.push({0,startY,startX,0});
        const int fullKey = calcFullKey(grid);        
        while(!q.empty()){
            auto here = q.front();
            q.pop();
            const int key = here.key,y = here.y,x = here.x,dist = here.dist;
            if(visited[y][x]&(1ull<<fullKey)){
                return dist;
            }
            for(int dir=0;dir<4;++dir){
                const int cy = y+dy[dir],cx = x+dx[dir];
                if(checkValid(cy,cx) && (visited[cy][cx]&(1ull<<key))==0){
                    if(grid[cy][cx]==ROAD){
                        visited[cy][cx] |= 1ull<<key;
                        q.push({key,cy,cx,dist+1});
                    }else if(checkLowerCase(grid[cy][cx])){
                        const int newKey = key|(1<<getKeyNum(grid[cy][cx]));
                        visited[cy][cx] |= 1ull<<key;
                        visited[cy][cx] |= 1ull<<newKey;
                        q.push({newKey,cy,cx,dist+1});
                    }else if(checkUpperCase(grid[cy][cx])){
                        const int wallNum = getWallNum(grid[cy][cx]);
                        if(key&(1<<wallNum)){
                            visited[cy][cx] |= 1ull<<key;
                            q.push({key,cy,cx,dist+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};