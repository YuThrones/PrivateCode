// 一开始搞错写成LRU了╮(╯▽╰)╭
// 这道题要求get和put都是O(1)复杂度，也就是说，数据结构基本就是要依赖unordered_map
// 额外增加一个list用来维护次数的顺序，用一个node来存储相同访问次数的key，
// 然后用keydata存储一个key对应的node里面的list的迭代器，每次次数加1，就通过这个迭代器O(1)复杂度删除，
// 然后在新的node里面把自己加进去

#include <unordered_map>
#include <iostream>
#include <list>

// 搞错了，写成了LRU╮(╯▽╰)╭
// class LFUCache {
// public:
//     LFUCache(int capacity) {
//         m_capacity = capacity;
//     }
    
//     int get(int key) {
//         auto it = m_kvMap.find(key);
//         if (it == m_kvMap.end()) return -1;

//         updateTime(key);
//         return it->second;
//     }
    
//     void put(int key, int value) {
//         auto it = m_kvMap.find(key);
//         if (it != m_kvMap.end()) {
//             updateTime(key);
//             return;
//         }
//         m_kvMap[key] = value;
//         m_list.push_back(key);
//         m_itMap[key] = --m_list.end();
//         tryDelete();
//     }

//     void updateTime(int key) {
//         auto listIt = m_itMap[key];
//         m_list.erase(listIt);
//         m_list.emplace_back(key);
//         m_itMap[key] = --m_list.end();
//     }

//     void tryDelete() {
//         if (m_kvMap.size() <= m_capacity) return;
//         int key = m_list.front();
//         m_kvMap.erase(key);
//         m_itMap.erase(key);
//         m_list.pop_front();
//     }

// private:
//     int m_capacity;
//     std::unordered_map<int, int> m_kvMap;
//     std::unordered_map<int, std::list<int>::iterator> m_itMap;
//     std::list<int> m_list;
// };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node {
    int times;
    std::list<int> keyList;
};

struct KeyData {
    int key;
    int value;
    int times;
    int timeFlag;
    std::list<int>::iterator keyIt;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        m_capacity = capacity;
        m_timeCount = 0;
    }
    
    int get(int key) {
        auto it = m_dataMap.find(key);
        if (it == m_dataMap.end()) return -1;
        auto data = it->second;
        updateTimes(data);
        return data->value;
    }
    
    void put(int key, int value) {
        auto it = m_dataMap.find(key);
        if (it != m_dataMap.end()) {
            KeyData* data = it->second;
            data->value = value;
            updateTimes(data);
            return;
        }

        checkDelete();

        KeyData* data = new KeyData();
        data->key = key;
        data->value = value;
        data->times = 0;
        data->timeFlag = ++m_timeCount;
        m_dataMap[key] = data;
        insertDataToNode(m_list.begin(), data);
    }

private:
    int m_capacity;
    int m_timeCount;
    std::unordered_map<int, KeyData*> m_dataMap;
    std::unordered_map<int, std::list<Node*>::iterator> m_nodeMap;
    std::list<Node*> m_list;

    void updateTimes(KeyData* data) {
        data->timeFlag = ++m_timeCount;

        // delete old data

        auto nodeIt = m_nodeMap[data->times];
        auto node = *(nodeIt);
        node->keyList.erase(data->keyIt);

        data->times++;
        insertDataToNode(++nodeIt, data);

        if (!node->keyList.size()) {
            m_list.erase(m_nodeMap[node->times]);
            m_nodeMap.erase(node->times);
        }
    }

    void insertDataToNode(std::list<Node*>::iterator insertIterator, KeyData* data) {
        Node* newNode;
        if (m_nodeMap.find(data->times) == m_nodeMap.end()) {
            newNode = new Node();
            auto insIt = m_list.insert(insertIterator, newNode);
            // m_list.emplace_back(newNode);
            newNode->times = data->times;
            m_nodeMap[data->times] = insIt;
        }

        else {
            newNode = *(m_nodeMap[data->times]);
        }

        newNode->keyList.push_back(data->key);
        data->keyIt = --newNode->keyList.end();
    }

    void checkDelete() {
        if (m_dataMap.size() < m_capacity) return;

        Node* first = m_list.front();
        int key = first->keyList.front();
        m_dataMap.erase(key);
        first->keyList.pop_front();
        if (!first->keyList.size()) {
            m_list.pop_front();
            m_nodeMap.erase(first->times);
        }
    }
};


int main() {
    int capacity = 2;
    LFUCache* obj = new LFUCache(capacity);

    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1) << std::endl;
    obj->put(3, 3);
    std::cout << obj->get(2) << std::endl;
    std::cout << obj->get(3) << std::endl;
    obj->put(4, 4);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(4) << std::endl;

    // int capacity = 3;
    // LFUCache* obj = new LFUCache(capacity);

    // obj->put(2, 2);
    // obj->put(1, 1);
    // std::cout << obj->get(2) << std::endl;
    // std::cout << obj->get(1) << std::endl;
    // std::cout << obj->get(2) << std::endl;
    // obj->put(3, 3);
    // obj->put(4, 4);
    // std::cout << obj->get(3) << std::endl;
    // std::cout << obj->get(2) << std::endl;
    // std::cout << obj->get(1) << std::endl;
    // std::cout << obj->get(4) << std::endl;
}