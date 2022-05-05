#include <iostream>
#include <random>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;


const int SKIP_NODE_HEIGHT = 32;

class SkipListNode 
{
public:
    SkipListNode* next[SKIP_NODE_HEIGHT + 1];
    int height = 0;
    double score = 0;
    string key;
    int nextDis[SKIP_NODE_HEIGHT + 1];

    SkipListNode()
    {
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            next[i] = nullptr;
            nextDis[i] = 0;
        }
    }

    int randomLevel()
    {
        height = 1;
        while (height < SKIP_NODE_HEIGHT)
        {
            if (rand() < RAND_MAX / 2)
            {
                break;
            }
            ++height;
        }
        return this->height;
    }
};


class SkipList 
{
public:
    unordered_map<string, SkipListNode*> my_dict;
    SkipListNode* head = nullptr;
    SkipList()
    {
        head = new SkipListNode();
        head->height = SKIP_NODE_HEIGHT;
    }

    bool addNode(string key, double score)
    {
        SkipListNode* temp;
        if (my_dict.find(key) != my_dict.end())
        {
            temp = my_dict[key];
            
            if (temp->score == score)
            {
                return true;
            }

            // 修改分数采用移除再加入的方式
            removeNode(key);
        }
        temp = new SkipListNode();
        temp->key = key;
        temp->score = score;
        temp->randomLevel();
        my_dict[key] = temp;

        // 记录跳过的节点和距离，方便用于计算排名
        SkipListNode* cur = head;
        int level = SKIP_NODE_HEIGHT;
        SkipListNode* skipedNodes[SKIP_NODE_HEIGHT + 1];
        int skipedDistance[SKIP_NODE_HEIGHT + 1];
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            skipedNodes[i] = cur;
            skipedDistance[i] = 0;
        }

        while(cur->next[0])
        {
            while(!cur->next[level] || cur->next[level]->score < score)
            {
                if (!level) break;
                --level;
                skipedNodes[level] = cur;
            }

            while(cur->next[level] && cur->next[level]->score >= score)
            {
                skipedDistance[level] += cur->nextDis[level];
                cur = cur->next[level];
                skipedNodes[level] = cur;
            }

            if (level > 0)
            {
                --level;
                skipedNodes[level] = cur;
            }
            else
            {
                break;
            }
        }

        for (int i = level; i >= 0; --i)
        {
            skipedNodes[i] = cur;
        }

        // 经过上面的查找，cur就是上一个节点，直接加入即可
        int totalSkip = 1;
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            if (i <= temp->height)
            {
                temp->next[i] = skipedNodes[i]->next[i];
                skipedNodes[i]->next[i] = temp;
                temp->nextDis[i] = skipedNodes[i]->nextDis[i] - totalSkip + 1;
                skipedNodes[i]->nextDis[i] = totalSkip;
                totalSkip += skipedDistance[i];
            }
            else
            {
                skipedNodes[i]->nextDis[i] += 1;
            }
        }
        return true;
    }

    bool removeNode(string key)
    {
        if (my_dict.find(key) == my_dict.end())
        {
            return false;
        }

        SkipListNode* temp = my_dict[key];
        int score = temp->score;
        SkipListNode* cur = head;
        int level = SKIP_NODE_HEIGHT;
        SkipListNode* skipedNodes[SKIP_NODE_HEIGHT + 1];
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            skipedNodes[i] = cur;
        }

        while(cur->next[0])
        {
            while(!cur->next[level] || cur->next[level]->score <= score)
            {
                if (!level) break;
                if (level <= temp->height && score == cur->next[level]->score)
                {
                    // 高度小于temp的需要检查下一个是否是temp，高度大于的在分数相同时只能直接下降
                    break;
                }

                --level;
                skipedNodes[level] = cur;
            }

            while(cur->next[level] && cur->next[level]->score >= score && cur->next[level] != temp)
            {
                if (level > temp->height && score == cur->next[level]->score)
                {
                    // 高度小于temp的需要检查下一个是否是temp，高度大于的在分数相同时只能直接下降
                    break;
                }
                cur = cur->next[level];
                skipedNodes[level] = cur;
            }

            if (level > 0)
            {
                --level;
                skipedNodes[level] = cur;
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {

            if (i <= temp->height)
            {
                skipedNodes[i]->next[i] = temp->next[i];
                skipedNodes[i]->nextDis[i] = skipedNodes[i]->nextDis[i] + temp->nextDis[i] - 1;
            }
            else
            {
                skipedNodes[i]->nextDis[i] -= 1;
            }
        }

        my_dict.erase(key);
        delete temp;
        return true;
    }

    void print()
    {
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            cout << i << ": ";
            SkipListNode* cur = head;
            while(cur)
            {
                cout << cur->score << "->" << cur->nextDis[i] << " ";
                cur = cur->next[i];
            }
            cout << endl;
        }
    }

    bool valid()
    {
        for (int i = 0; i <= SKIP_NODE_HEIGHT; ++i)
        {
            SkipListNode* cur = head;
            SkipListNode* last = nullptr;
            while(cur)
            {
                if ((last != nullptr) && (last != head) && (last->score < cur->score))
                {
                    return false;
                }
                last = cur;
                cur = cur->next[i];
            }
        }

        return true;
    }

    SkipListNode* findFirstGreaterNode(double score)
    {
        // 获取第一个分数大于给定score的节点
        SkipListNode* cur = head;
        int level = SKIP_NODE_HEIGHT;

        while(cur->next[0] && level >= 0)
        {
            while((!cur->next[level] || cur->next[level]->score < score) && level > 0)
            {
                --level;
            }

            while(cur->next[level] && cur->next[level]->score > score)
            {
                cur = cur->next[level];
            }

            --level;
        }

        if (cur == head) return nullptr;

        return cur;
    }

    SkipListNode* findFirstLessNode(double score)
    {
        // 获取第一个分数小于给定score的节点
        SkipListNode* cur = head;
        int level = SKIP_NODE_HEIGHT;

        while(cur->next[0] && level >= 0)
        {
            while((!cur->next[level] || cur->next[level]->score < score) && level > 0)
            {
                --level;
            }

            while(cur->next[level] && cur->next[level]->score >= score)
            {
                cur = cur->next[level];
            }

            --level;
        }

        return cur->next[0];
    }
};


int main()
{
    SkipList slist = SkipList();

    const int count = 50000;

    for (int i = 0; i < count; ++i) 
    {
        // cout << "deal" << i << endl;
        slist.addNode(to_string(rand()), rand());
        slist.removeNode(to_string(rand()));
        int r = rand();
        SkipListNode* temp = slist.findFirstGreaterNode(r);
        if (temp && temp->score <= r) 
            cout << "error1" << endl;
        temp = slist.findFirstLessNode(r);
        if (temp && temp->score >= r) 
            cout << "error2" << endl;
        slist.valid();
    }

    // slist.print();
    cout << slist.valid();
    return 0;
}