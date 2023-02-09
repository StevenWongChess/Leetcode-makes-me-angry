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
public:
    using ittype = vector<NestedInteger>::iterator;
    stack<pair<ittype, ittype>> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        auto tmp = s.top().first;
        ++s.top().first;
        return tmp->getInteger();
    }
    
    bool hasNext() {
        while(!s.empty()){
            auto& i = s.top();
            if(i.first == i.second){
                s.pop();
                continue;
            }
            if(i.first->isInteger())
                return true;
            // i.first++;
            auto tmp = i.first;
            ++i.first;
            auto &it = tmp->getList();
            s.push({it.begin(), it.end()});
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */