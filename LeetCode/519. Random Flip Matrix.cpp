最佳答案直接放弃随机，直接遍历，那确实是快，但是有点取巧了。。。

class Solution {
public:
    int i = 0;
    int j = 0;
    int im,in;
    bool f=0;
    Solution(int m, int n) {
        i=0;j=0;im=m;in=n;
    }

    vector<int> flip() {
        f=0;
        vector<int> v;
        v.push_back(i);
        v.push_back(j);

        if(j<in-1){
            j++;
        }else{
            j=0;
            if(i<im-1){
                i++;
            } else {
                i=0;
            }
        }
        

        return v;
    }

    void reset() {
        if(f==0){
            f=1;
            return;
        }
        if(i<im-1){
            i++;
        } else {
            i=0;
        }
        if(j<in-1){
            j++;
        } else {
            j=0;
        }
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

class Solution {
public:
    vector<int> index;
    int count = 0;
    int row;
    int col;

    Solution(int m, int n) {
        row = m;
        col = n;
        index.reserve(m * n);
        for (int i = 0; i < m * n; ++i) {
            index.push_back(i);
        }
        std::srand(std::time(nullptr));
    }
    
    vector<int> flip() {
        vector<int> result;
        if (count >= row * col) {
            return result;
        }

        int randInt = std::rand() % (row * col - count) + count;
        if (randInt != count) {
            swap(index[count], index[randInt]);
        }
        result.push_back(index[count] / col);
        result.push_back(index[count] % col);
        ++count;
        return result;
    }
    
    void reset() {
        count = 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */