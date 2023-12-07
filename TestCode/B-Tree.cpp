#include <iostream>
#include <cmath>
#include <string>
#include <tuple>
#include <random>
#include <array>
#include <unordered_set>
#include <vector>

template<typename T, int M>
class BTreeNode;

template<typename T, int M>
class BTree;

template<typename T, int M>
class BTreeNode {
public:
    friend class BTree<T, M>;
    BTreeNode(bool isLeaf) {
        m_count = 0;
        m_isLeaf = isLeaf;
    }

    void Print(int index, int level) {
        // print the tree

        if (!m_count) {
            std::cout << std::string(level * 4, ' ') << "Empty tree" << std::endl;
            return;
        }
        std::cout << std::string(level * 4, ' ') << "{index[" << std::to_string(index) << "] "
        << (m_isLeaf? "is leaf": "not leaf")
        << ", key num:" << m_count << std::endl;
        for (int i = 0; i < m_count; ++i) {
            if (!m_isLeaf) {
                m_childs[i]->Print(i, level + 1);
            }
            std::cout << std::string(level * 4, ' ') << m_keys[i] << std::endl;
        }

        if (!m_isLeaf) {
            m_childs[m_count]->Print(m_count, level + 1);
        }
    
        std::cout << std::string(level * 4, ' ') << "}index[" << std::to_string(index) << "] "
        << "end" << std::endl;
    }

    int FindKey(T k) {
        return std::distance(m_keys, std::lower_bound(m_keys, m_keys + m_count, k));
    }

    bool Insert(T k) {
        // return false if need split
        if (!m_count) {
            m_keys[m_count++] = k;
            return true;
        }
        int pos = FindKey(k);

        // k already in m_Keys
        if (m_keys[pos] == k) return true;

        if (m_isLeaf) {
            // is this is leaf, just insert here
            for (int i = m_count; i > pos; --i) {
                m_keys[i] = m_keys[i - 1];
            }
            m_keys[pos] = k;
            ++m_count;
        }
        else {
            // if this is not left, insert child
            bool check = m_childs[pos]->Insert(k);
            if (!check) {
                // child need split

                BTreeNode<T, M>* left = m_childs[pos];
                BTreeNode<T, M>* right;
                T midData;
                std::tie(midData, right) = left->Split();

                // add mid to parent
                for (int i = m_count; i > pos; --i) {
                    std::swap(m_keys[i], m_keys[i - 1]);
                    std::swap(m_childs[i + 1], m_childs[i]);
                }
                m_keys[pos] = midData;
                m_childs[pos + 1] = right;
                ++m_count;
            }
        }
        return m_count < M;
    }

    bool Search(T k) {
        if (!m_count) return false;
        int pos = FindKey(k);
        if (pos > m_count) return false;
        if (pos < m_count && m_keys[pos] == k) return true;
        if (m_isLeaf) return false;
        return m_childs[pos]->Search(k);
    }

    std::tuple<T, BTreeNode<T, M>*> Split() {
        BTreeNode<T, M>* right = new BTreeNode<T, M>(m_isLeaf);

        int mid = ceil((float)m_count / 2) - 1;
        for (int i = mid + 1; i < m_count; ++i) {
            right->m_keys[i - mid - 1] = m_keys[i];
        }

        for (int i = mid; i < m_count + 1; ++i) {
            right->m_childs[i - mid] = m_childs[i + 1];
        }
        m_count = mid;
        right->m_count = M - mid - 1;

        return {
            m_keys[mid],
            right,
        };
    }

    bool Delete (T k) {
        // return true if delete success, return false if no delete

        // empty tree, cannot find k
        if (!m_count) return false;
        int pos = FindKey(k);

        if (pos < 0 || pos > m_count) {
            std::cout << "Something wrong" << std::endl;
            return false;
        }

        if (m_isLeaf && (pos == m_count || m_keys[pos] != k)) {
            // cannot find k
            return false;
        }

        if (pos < m_count && m_keys[pos] == k) {
            if (m_isLeaf) {
                return DeleteFromLeaf(pos);
            }
            else {
                return DeleteFromNonLeaf(pos);
            }
        }

        // handle by child
        BTreeNode<T, M>* child = m_childs[pos];
        child->Delete(k);
        HandlePoor(pos);

        return true;
    }

    bool DeleteFromLeaf(int pos) {
        // just delete the key
        --m_count;
        for (int i = pos; i < m_count; ++i) {
            m_keys[i] = m_keys[i + 1];
        }

        return true;
    }

    bool DeleteFromNonLeaf(int pos) {
        //TODO: fill with child key
        BTreeNode<T, M>* child = m_childs[pos];
        T preKey = child->MaxEdgeKey(false);
        m_keys[pos] = preKey;
        child->Delete(preKey);
        HandlePoor(pos);
        return true;
    }

    void HandlePoor(int pos) {
        BTreeNode<T, M>* child = m_childs[pos];
        if (!child->NeedMerge()) {
            return;
        }

        BTreeNode<T, M>* left;
        BTreeNode<T, M>* right;

        if (pos > 0 && m_childs[pos - 1]->isRich()) {
            // use left brother
            BorrowFromPrev(pos);
        }
        else if (pos < m_count && m_childs[pos + 1]->isRich()) {
            // use right brother
            BorrowFromNext(pos);
        }
        else {
            // merge brother
            if (pos < m_count) {
                Merge(pos);
            }
            else {
                Merge(pos - 1);
            }
        }
    }

    void BorrowFromPrev(int pos) {
        BTreeNode<T, M>* left = m_childs[pos - 1];
        BTreeNode<T, M>* right = m_childs[pos];
        
        for (int i = right->m_count; i > 0; --i) {
            right->m_keys[i] = right->m_keys[i - 1];
        }

        for (int i = right->m_count + 1; i > 0; --i) {
            right->m_childs[i] = right->m_childs[i - 1];
        }

        right->m_keys[0] = m_keys[pos - 1];
        right->m_childs[0] = left->m_childs[left->m_count];
        ++right->m_count;

        m_keys[pos - 1] = left->m_keys[left->m_count - 1];

        --left->m_count;
    }

    void BorrowFromNext(int pos) {
        BTreeNode<T, M>* left = m_childs[pos];
        BTreeNode<T, M>* right = m_childs[pos + 1];

        left->m_keys[left->m_count] = m_keys[pos];
        left->m_childs[left->m_count + 1] = right->m_childs[0];
        ++left->m_count;

        m_keys[pos] = right->m_keys[0];

        for (int i = 0; i < right->m_count; ++i) {
            right->m_keys[i] = right->m_keys[i + 1];
        }

        for (int i = 0; i < right->m_count + 1; ++i) {
            right->m_childs[i] = right->m_childs[i + 1];
        }

        --right->m_count;
    }

    bool IsFull() {
        return m_count == M - 1;
    }

    bool isRich() {
        return m_count > ceil((float)M / 2) - 1;
    }

    bool NeedMerge() {
        return m_count < ceil((float)M / 2) - 1;
    }

    bool IsEmpty() {
        return m_count == 0;
    }

    void Merge(int pos) {
        T midData = m_keys[pos];
        BTreeNode<T, M>* left = m_childs[pos];
        BTreeNode<T, M>* right = m_childs[pos + 1];

        left->m_keys[left->m_count] = midData;
        for (int i = 0; i < right->m_count; ++i) {
            left->m_keys[left->m_count + i + 1] = right->m_keys[i];
            left->m_childs[left->m_count + i + 1] = right->m_childs[i];
        }
        left->m_childs[left->m_count + right->m_count + 1] = right->m_childs[right->m_count];
        left->m_count = left->m_count + right->m_count + 1;

        delete right;

        for (int i = pos; i < m_count; ++i) {
            m_keys[i] = m_keys[i + 1];
            m_childs[i + 1] = m_childs[i + 2];
        }
        m_childs[m_count] = nullptr;
        --m_count;
    }

    void StoreKey(std::vector<T>& vec) {
        if (!m_count) return;

        for (int i = 0; i < m_count; ++i) {
            vec.push_back(m_keys[i]);
        }

        if (!m_isLeaf) {
            for (int i = 0; i <= m_count; ++i) {
                m_childs[i]->StoreKey(vec);
            }
        }
        
    }

    T MaxEdgeKey(bool isLeft) {
        BTreeNode<T, M>* cur = this;
        while(!cur->m_isLeaf) {
            cur = (isLeft ? cur->m_childs[0] : cur->m_childs[cur->m_count]);
        }
        
        return isLeft ? cur->m_keys[0] : cur->m_keys[cur->m_count - 1];
    }

    bool CheckSort() {
        if (!m_count) return true;
        for (int i = 0; i < m_count - 1; ++i) {
            if (m_keys[i] > m_keys[i + 1]) {
                PrintNotSort(m_keys[i], m_keys[i + 1]);
                return false;
            }
            if (m_isLeaf) continue;
            BTreeNode<T, M>* child = m_childs[i];
            if (m_keys[i] < child->m_keys[child->m_count - 1]) {
                PrintNotSort(m_keys[i], child->m_keys[child->m_count - 1]);
                return false;
            }
            child = m_childs[i + 1];
            if (m_keys[i] > child->m_keys[0]) {
                PrintNotSort(m_keys[i], child->m_keys[0]);
                return false;
            }
        }

        if (!m_isLeaf) {
            for (int i = 0; i <= m_count; ++i) {
                if (!m_childs[i]->CheckSort()) {
                return false;
            }
            }
        }
        
        return true;
    }

    void PrintNotSort(int left, int right) {
        std::cout << "\n" << left << " " << right << " not sort" << std::endl;
        Print(0, 0);
    }

    bool SelfCheck() {
        if (!CheckSort()) return false;

        if (NeedMerge()) {
            std::cout << "size wrong" << std::endl;
            return false;
        }

        if (!m_isLeaf) {
            for (int i = 0; i <= m_count; ++i) {
                if (!m_childs[i]->SelfCheck()) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int m_count;
    T m_keys[M];
    BTreeNode<T, M>* m_childs[M + 1];
    bool m_isLeaf;
};



template<typename T, int M>
class BTree {
public:
    BTree() {
        root = new BTreeNode<T, M>(true);
    }

    void Insert(T k) {
        if (!root->Insert(k)) {
            // need to split
            BTreeNode<T, M>* left = root;
            BTreeNode<T, M>* right;
            T midData;
            std::tie(midData, right) = left->Split();

            root = new BTreeNode<T, M>(false);
            root->m_count = 1;
            root->m_keys[0] = midData;
            root->m_childs[0] = left;
            root->m_childs[1] = right;
        }
    }

    void PrintTree() {
        root->Print(0, 0);
    }

    bool Search(T k) {
        return root->Search(k);
    }

    bool Delete(T k) {
        bool res = root->Delete(k);

        // maybe need to cut the height
        if (root->IsEmpty() && root->m_childs[0] && !root->m_isLeaf) {
            BTreeNode<T, M>* old = root;
            root = root->m_childs[0];
            delete old;
        }

        return res;
    }

    bool CheckRepeat() {
        std::unordered_set<T> uSet;
        std::vector<T> vec;
        root->StoreKey(vec);
        for (auto key: vec) {
            if (uSet.find(key) != uSet.end()) {
                return true;
            }
            uSet.insert(key);
        }
        return false;
    }

    bool CheckSort() {
        return root->CheckSort();
    }

    bool SelfCheck() {
        if (root->m_isLeaf) return true;
        for (int i = 0; i <= root->m_count; ++i) {
            if(!root->m_childs[i]->SelfCheck()) return false;
        }
        return true;
    }


private:
    BTreeNode<T, M>* root;
};


int main() {
    int lower_bound = 0;
    int uppder_bound = 200;
    constexpr int M = 5;
    int num = 10000;
    int deleteNum = 10000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(lower_bound, uppder_bound);

    BTree<int, M> tree1;
    for (int i = 0; i < num; ++i) {
        int randNum = distribution(gen);
        tree1.Insert(randNum);
        if (!tree1.SelfCheck()) {
            std::cout << "Insert error " << randNum << " " << tree1.Search(randNum) << std::endl;
            tree1.PrintTree();
            return 0;
        }
    }
    tree1.PrintTree();
    std::cout << "InsertEnd" << std::endl;

    for (int i = 0; i < deleteNum; ++i) {
        int randNum = distribution(gen);
        tree1.Delete(randNum);
        if (!tree1.SelfCheck()) {
            tree1.PrintTree();
            std::cout << "Delete error " << randNum << " " << tree1.Search(randNum) << std::endl;
            return 0;
        }
    }
    tree1.PrintTree();
    std::cout << "DeleteEnd" << std::endl;
    return 0;
}