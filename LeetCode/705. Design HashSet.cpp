#include <vector>
using namespace std;

class MyHashSet {
    int bucketSize = 1000000;
    vector<vector<int>> bucket;
    public:
        MyHashSet() {
            bucket.resize(bucketSize);            
        }
        
        void add(int key) {
            int bucketIndex = key % bucketSize;
            for (int i = 0; i < bucket[bucketIndex].size(); i++) {
                if (bucket[bucketIndex][i] == key) {
                    return;
                }
            }
            bucket[bucketIndex].push_back(key);
        }
        
        void remove(int key) {
            int bucketIndex = key % bucketSize;
            for (int i = 0; i < bucket[bucketIndex].size(); i++) {
                if (bucket[bucketIndex][i] == key) {
                    bucket[bucketIndex].erase(bucket[bucketIndex].begin() + i);
                    return;
                }
            }
        }
        
        bool contains(int key) {
            int bucketIndex = key % bucketSize;
            return find(bucket[bucketIndex].begin(), bucket[bucketIndex].end(), key) != bucket[bucketIndex].end();
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */


int main() {

}