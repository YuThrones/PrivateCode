// 这个解法看起来比较冗长复杂，但是和我的思路有一定的共同性
// 核心思想就是，便利时先把左边界造成的突变点记录，右边界按照x坐标放到优先队列里面，后面处理
// 最开始是假设当前正在处理从-1到INT_MAX，高度为0的矩形
// 在遍历过程中，如果遇到开始位置小于当前矩形的结束位置，并且高度大于当前高度的，说明有一个突变点，这时候需要处理这个矩形
// 把起始位置和高度都改成当前矩形的，左边界加入答案，右边界加入优先队列，开始处理新的矩形
// 在遍历过程中如果遇到开始位置等于当前结束位置的，先把结束位置前的优先队列进行结算，由于当前高度必定是之前的最大高度，所以这时候优先队列中，结束位置小于等于当前结束位置的，必然被覆盖，无须处理
// 如果遇到一个结束位置大于当前结束位置的，需要比较这个位置对应的高度和当前位置高度的值，如果相等，两者的结束位置较小的为下一个要处理的矩形的结束位置，如果不相等，取高度更大者为当前要处理的矩形
// 在遍历过程中，遇到开始位置大于当前结束位置的，跟等于类似，先把前面的矩形都进行结算，然后处理当前矩形
// 这个算法效率很高，但是感觉写法上可以改下，应该可以更容易理解，有些情况估计可以合并

#include <vector>
#include <queue>
#include <cstdint>
#include <climits>
// #include <stdint.h>
using namespace std;
using std::uint32_t;


struct mycomp {
  bool operator()(pair<int, uint32_t>& a,pair<int,uint32_t>& b) // overloading both operators 
  {
      return a.first < b.first; 
   }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,uint32_t>,vector<pair<int,uint32_t>>, mycomp> myqueue;
        int n = buildings.size();
        vector<vector<int>> ret;
        int x, h, cmax = 0;
        int32_t end = INT32_MAX;
        int32_t st = -1;
        
        for (int i = 0;i < n; i++) {
            int pos = buildings[i][0];
            int e = buildings[i][1];
            int h = buildings[i][2];
            bool isSaving = false;
            if (pos < end) {
                if (st == pos) {
                    if (h > cmax && ret.size()) {
                        ret.back()[1] = h;
                        cmax = h;
                        end = e;
                    }
                    isSaving = true;
                }
                else {
                    if (h > cmax) {
                        cmax = h;
                        end = e;
                        st = pos;
                        ret.push_back(vector<int>({pos, h}));
                        isSaving = true;
                    }
                    else if (h == cmax) {
                        if (e > end) {
                            isSaving = true;
                            end = e;
                        }
                    }    
                    else /*h < cmax*/ {
                        if (e > end) {
                            isSaving = true;
                        }
                    }
                }
            }
            else if (pos == end) {
                // need check container decide cmax and end
                bool isDone = false;
                while(myqueue.size()) {
                    pair<int, uint32_t> p = myqueue.top();
                    int hh = p.first;
                    uint32_t ee = p.second;
                    if (ee <= end) {
                        myqueue.pop(); 
                    }
                    else {

                        if (hh > h) {
                            cmax = hh;
                            end = ee;

                            if (e > ee)
                                isSaving = true;

                            st = pos;
                            ret.push_back(vector<int>({pos, cmax}));
                        }
                        else if (hh < h) {
                            cmax = h;
                            end  = e;
                            isSaving = true;

                            st = pos;
                            ret.push_back(vector<int>({pos, cmax}));
                        }
                        else {
                            cmax = h;
                            end = max((int)ee, e);
                            isSaving = true;
                        }

                        isDone = true;
                        break;
                    }
                }
                if (isDone == false) {
                    int ocmax = cmax;
                    cmax = h;
                    end  = e;
                    isSaving = true;
                    if (h != ocmax) {
                        st = pos;
                        ret.push_back(vector<int>({pos, cmax}));
                    }
                }
            }
            else /*pos > end*/ {
                // need check container decide cmax and end
                while(myqueue.size()) {
                    pair<int, uint32_t> p = myqueue.top();
                    int hh = p.first;
                    uint32_t ee = p.second;
                    
                    if (ee <= end) {
                        myqueue.pop(); 
                    }
                    else {
                        cmax = hh;
                        st = end;
                        ret.push_back(vector<int>({end, cmax}));
                        end = ee;

                        if (end >= pos)
                            break;
                    }
                }

                if (end < pos) {
                    cmax = 0;
                    st = pos;
                    ret.push_back(vector<int>({end, 0}));
                    end = INT_MAX;
                }

                if (cmax < h) {
                    cmax = h; end  = e;
                    st = pos;
                    ret.push_back(vector<int>({pos, cmax}));
                }
                else if( cmax == h) {
                    end  = max(end, e);
                }
                else {
                   //do nothing 
                   ;
                }
                isSaving = true;
            }

            if (isSaving) {
                //cout << "push to c " << h << " " << e << endl;
                myqueue.push(make_pair(h, e));
            }
        }

        myqueue.push(make_pair(0, UINT32_MAX));
        while(myqueue.size()) {
            pair<int, uint32_t> p = myqueue.top();
            int hh = p.first;
            uint32_t ee = p.second;
            if (ee <= (uint32_t)end) {
                myqueue.pop(); 
            }
            else {
                ret.push_back(vector<int>({end, hh}));
                end = ee;
            }
        }

        vector<vector<int>> rret;
        rret.push_back(ret[0]);
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i][1] == ret[i-1][1]) {
                continue;
            }
            else {
                rret.push_back(ret[i]);
            }
        }

        return rret;
    }
};


int main() {
    const int row = 5;
    const int col = 3;

    int input[row][col] = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // int input[row][col] = {{0,2147483647,2147483647}};
    vector<vector<int>> in;
    for (int i = 0; i < row; ++i) {
        in.push_back(vector<int>());
        for (int j = 0; j < col; ++j) {
            in[i].push_back(input[i][j]);
        }
    }
    Solution s = Solution();
    s.getSkyline(in);
    return 0;
}