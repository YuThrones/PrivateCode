// 唯一需要注意的优化是random存一下vector应付连续getrandom的情况

#include<unordered_map>
#include<random>
using namespace std;


class RandomizedCollection {
public:
    unordered_map<int, int> umap;
    vector<int> rad;
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        rad.clear();
        if (umap[val] <= 0) {
            umap[val] += 1;
            return true;
        }
        umap[val] += 1;
        return false;
    }
    
    bool remove(int val) {
        if (umap[val] > 0) {
            umap[val] -= 1;
            rad.clear();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if (!rad.empty()) return rad[rand() % rad.size()];
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            for (int i = 0; i < it->second; ++i) rad.push_back(it->first);
        }
        if (!rad.empty()) return rad[rand() % rad.size()];
        return -1;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedCollection col;
    col.insert(1);
    col.insert(2);
    col.insert(2);
    col.insert(1);
    col.insert(2);
    col.insert(2);
    col.remove(1);
    col.remove(2);
    col.remove(2);
    col.remove(2);
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
    col.getRandom();
}