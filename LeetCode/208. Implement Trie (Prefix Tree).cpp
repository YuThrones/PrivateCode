// 前缀树的构建，用边记录字符，并且用一个标志位记录是否是一个终点
// 和最快答案对比，差距应该在于我没有用char数字，而是用unordered_map，因为没有假设只有26个字母，其他应该区别不大

#include<iostream>
#include<unordered_map>
using namespace std;

class Trie {
public:
    unordered_map<char, Trie*> trie_map;
    bool is_end = false;

    Trie() {
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (auto c: word) {
            if (cur->trie_map.find(c) == cur->trie_map.end()) {
                cur->trie_map[c] = new Trie();
            }
            cur = cur->trie_map[c];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        int count = 0;
        Trie* cur = this;
        for (auto c: word) {
            if (cur->trie_map.find(c) == cur->trie_map.end()) {
                return false;
            }
            cur = cur->trie_map[c];
        }
        return cur->is_end;
    }
    
    bool startsWith(string prefix) {
        int count = 0;
        Trie* cur = this;
        for (auto c: prefix) {
            if (cur->trie_map.find(c) == cur->trie_map.end()) {
                return false;
            }
            cur = cur->trie_map[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie t = Trie();
    t.insert("app");
    t.insert("apple");
    t.insert("bear");
    t.insert("add");
    cout << t.search("ad") << endl;
    

    return 0;
}