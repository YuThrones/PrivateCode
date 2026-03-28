// 一开始处理遗漏重复插入的问题了，补充了一个keymap存储旧值

struct Node{
    Node* Map[26];
    int val = 0;

    Node() {
        for (int i = 0; i < 26; i++) Map[i] = nullptr;
    }
};

class MapSum {
public:
    Node* root = nullptr;
    unordered_map<string, int> keyMap;
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int delta = val - keyMap[key];
        keyMap[key] = val;

        Node* cur = root;
        for (int i = 0; i < key.length(); ++i) {
            char k = key[i];
            if (cur->Map[k - 'a'] == nullptr) {
                cur->Map[k - 'a'] = new Node();
            }            
            cur = cur->Map[k - 'a'];
            cur->val += delta;
        }
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char k = prefix[i];
            if (cur->Map[k - 'a'] == nullptr) {
                return 0;
            }            
            cur = cur->Map[k - 'a'];
            
        }
        return cur->val;        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */