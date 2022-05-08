// 自己使用跳表来做，搜索可以使用的区间内的所有节点然后对比index，但是速度好像没有想象中的快
// 看了下最快答案，发现我想的太复杂了，事实上按照value和key排序，然后前后对比就行了
// 初看好像跟原始顺序对比value是一样的，但是有个问题就是，value可能差别很大，按照value排序，本身就可以去掉很大一部分不需要对比的index

#include <vector>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;



const int SKIP_NODE_HEIGHT = 32;

class SkipListNode 
{
public:
    SkipListNode* next[SKIP_NODE_HEIGHT + 1];
    int height = 0;
    int score = 0;
    int key;
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
    unordered_map<int, SkipListNode*> my_dict;
    SkipListNode* head = nullptr;
    SkipList()
    {
        head = new SkipListNode();
        head->height = SKIP_NODE_HEIGHT;
    }

    bool addNode(int key, int score)
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

    bool removeNode(int key)
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

    SkipListNode* findFirstGreaterNode(int score)
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

    SkipListNode* findFirstLessNode(int score)
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

    vector<SkipListNode*> findRangeNode(int maxScore, int minScore)
    {
        // 找到闭区间内的节点
        vector<SkipListNode*> res;

        if (maxScore < minScore) return res;

        SkipListNode* maxNode = findFirstGreaterNode(maxScore);
        if (!maxNode) maxNode = head;;

        SkipListNode* minNode = findFirstLessNode(minScore);

        SkipListNode* temp = maxNode->next[0];
        while(temp && temp != minNode)
        {
            res.push_back(temp);
            temp = temp->next[0];
        }

        return res;
    }
};



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        SkipList slist;
        t = abs(t);
        // t += 1;
        for (int i = 0; i < nums.size(); ++i) {
            // 算出当前位置能接受的大小范围，然后比较index
            int curMin = INT_MIN;
            int curMax = INT_MAX;
            if (nums[i] >= 0) 
            {
                if (nums[i] <= INT_MAX - t)
                {
                    curMax = nums[i] + t;
                }
                curMin = nums[i] - t;
            }
            else 
            {
                if (nums[i] >= INT_MIN + t)
                {
                    curMin = nums[i] - t;
                }
                curMax = nums[i] + t;
            }


            vector<SkipListNode*> res = slist.findRangeNode(curMax, curMin);
            for (int j = 0; j < res.size(); ++j) {
                int index = res[j]->key;
                if (abs(i - index) <= k) return true;
            }

            slist.addNode(i, nums[i]);
        }

        return false;
    }
    
    bool isOut(int a, int b) {
        if (a >= 0 && b >= 0) {
            return false;
        }
        if (a <= 0 && b <= 0) {
            return false;
        }
        if (a > 0) {
            if (a > INT_MAX + b) {
                return true;
            }
        }
        else {
            if (a < -INT_MAX + b) {
                return true;
            }    
        }
        return false;
    }
};


int main() {
    Solution s = Solution();
    // vector<int> input;
    // input.push_back(-2147483648);
    // input.push_back(2147483647);
    // input.push_back(4);
    // input.push_back(1);
    // input.push_back(6);
    // input.push_back(3);
    vector<int> input{1, 2, 3, 1};
    cout << s.containsNearbyAlmostDuplicate(input, 3, 0);
 
    // vector<int> input{1,5,9,1,5,9};
    // cout << s.containsNearbyAlmostDuplicate(input, 2, 3);
 
    // cout << s.containsNearbyAlmostDuplicate(input, 100, 1);
    return 0;
}