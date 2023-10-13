// 用哈希表加双向列表可以达到O(1)复杂度，但是实际跑起来不是最快，看了下最快答案，其实并不符合题目O(1)要求
// 算是取巧，在随机数据下可能可行，但是在精心设计的用例下应该会退化为O(n）

class AllOne {
public:
unordered_map<string, int> m;
    AllOne() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    void updateMin() {        
        _min.second = INT_MAX;
        for(auto & nd : m) {
            if(_min.second > nd.second) {
                _min.second = nd.second;
                _min.first = nd.first;
            }
        }
    }
    void updateMax() {        
        _max.second = INT_MIN;
        for(auto & nd : m) {
            if(_max.second < nd.second) {
                _max.second = nd.second;
                _max.first = nd.first;
            }
        }
    }
    void inc(string key) {
        auto & v = m[key];
        ++v;
        if(v > _max.second) {
            _max.second = v;
            _max.first = key;
        }
        if(key == _min.first) {
            updateMin();
        }
        if(_min.second > v || _min.first.empty()) {
            _min.first = key;
            _min.second = v;
        }
    }
    void dec(string key) {
        m[key]--;
        if(m[key] ==0)
            m.erase(key);
        _min.first = _max.first = "";
    }
    string getMaxKey() {
        if(!_max.first.empty())
            return _max.first;
        updateMax();
        return _max.first;
    }
    string getMinKey() {
        if(!_min.first.empty())
            return _min.first;

        updateMin();
        return _min.first;
    }
    pair<string, int> _min{{}, 0};
    pair<string, int> _max{{}, 0};
};

#include <unordered_set>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

struct Node {
    int count;
    unordered_set<string> strSet;
};


class AllOne {
public:
    list<Node*> nodeList;
    unordered_map<string, list<Node*>::iterator> strMap;

    AllOne() {
    }
    
    void inc(string key) {
        if (strMap.find(key) == strMap.end()) {
            if (nodeList.empty() || nodeList.front()->count != 1) {
                // 之前没这个key，插入先看看有没有数量为1的节点
                Node* node = new Node();
                node->count = 1;
                node->strSet.insert(key);
                nodeList.push_front(node);
                strMap[key] = nodeList.begin();
            }
            else {
                // 直接插入当前数量为1的node
                nodeList.front()->strSet.insert(key);
                strMap[key] = nodeList.begin();
            }
        }
        else {
            // 从原本的节点中删除，然后看一下+1的节点是否存在，不存在就信创建一个然后插入
            list<Node*>::iterator nodeIt = strMap.find(key)->second;
            int newCount = (*nodeIt)->count + 1;
            list<Node*>::iterator nextIt = next(nodeIt);
            if (nextIt == nodeList.end() || (*nextIt)->count != newCount) {
                Node* node = new Node();
                node->count = newCount;
                node->strSet.insert(key);
                nodeList.insert(nextIt, node);
                strMap[key] = prev(nextIt);
            }
            else {
                (*nextIt)->strSet.insert(key);
                strMap[key] = nextIt;
            }

            (*nodeIt)->strSet.erase(key);
            if ((*nodeIt)->strSet.empty()) {
                nodeList.erase(nodeIt);
            }
        }
    }
    
    void dec(string key) {
        if (strMap.find(key) == strMap.end()) return;
        auto nodeIt = strMap.find(key)->second;
        int newCount = (*nodeIt)->count - 1;

        auto prevIt = prev(nodeIt);

        if (newCount > 0) {
            if (prevIt == nodeList.end() || (*prevIt)->count != newCount) {
                Node* node = new Node();
                node->count = newCount;
                node->strSet.insert(key);
                nodeList.insert(nodeIt, node);
                strMap[key] = prev(nodeIt);
            }
            else {
                (*prevIt)->strSet.insert(key);
                strMap[key] = prevIt;
            }
        }
        else {
            // 这个key没了，全部删完
            strMap.erase(key);
        }

        (*nodeIt)->strSet.erase(key);
        if ((*nodeIt)->strSet.empty()) {
            nodeList.erase(nodeIt);
        }
    }
    
    string getMaxKey() {
        if (!nodeList.empty()) return *(nodeList.back()->strSet.begin());
        return "";
    }
    
    string getMinKey() {
        if (!nodeList.empty()) return *(nodeList.front()->strSet.begin());
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */