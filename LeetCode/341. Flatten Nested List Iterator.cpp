// 本来想储存下中间状态，不改变原本的数据，不过看了下最快答案，是直接自己重新组织存储顺序，想了想也差不多

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> _nestedList;
    int idx;
    
    void dfs(vector<int>& _nestedList, const vector<NestedInteger> &nestedList){
        for (auto const & e: nestedList){
            if (e.isInteger()) _nestedList.push_back(e.getInteger());
            else{
                dfs(_nestedList, e.getList());
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList):idx(0) {
        _nestedList.reserve(nestedList.size());
        dfs(_nestedList, nestedList);
    }
    
    int next() {
        return _nestedList[idx++];
    }
    
    bool hasNext() {
        return idx < _nestedList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */