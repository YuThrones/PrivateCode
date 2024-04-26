#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> vec;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        int index = mp.size();
        mp[val] = index;
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int index = mp[val];

        // 把vec上这个位置跟最后一个位置交换
        if (index != mp.size() - 1) {
            int last = vec[mp.size() - 1];
            mp[last] = index;
            vec[index] = last;
        }

        vec.pop_back();
        
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        if (mp.empty()) return -1;
        int size = mp.size();
        int index = rand() % size;
        return vec[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    RandomizedSet rset;
    rset.insert(0);
    rset.remove(0);
    rset.insert(-1);
    int ans = rset.getRandom();
    return 0;
}