class MyHashMap {
public:
    vector<vector<pair<int, int>>> data;
    int mod;
    MyHashMap() {
        mod = 3000;
        data.resize(mod);
    }
    
    void put(int key, int value) {
        int index = key % mod;
        for(auto& p : data[index]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }
        data[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = key % mod;
        for(auto& p : data[index]) {
            if(p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % mod;
        for(int i = 0; i < data[index].size(); ++i) {
            if(data[index][i].first == key) {
                data[index].erase(data[index].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */