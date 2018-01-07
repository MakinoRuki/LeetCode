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
    vector<pair<vector<NestedInteger>, int> > nlist;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nlist.push_back(make_pair(nestedList, 0));
    }

    int next() {
        while(true) {
            pair<vector<NestedInteger>, int> top = nlist.back();
            int idx = top.second;
            vector<NestedInteger> vi = top.first;
            if (idx == vi.size()) {
                nlist.pop_back();
            } else {
                break;
            }
        }
        while(true) {
            pair<vector<NestedInteger>, int>& top = nlist.back();
            int idx = top.second;
            vector<NestedInteger> vi = top.first;
            if (vi[idx].isInteger()) {
                top.second++;
                return vi[idx].getInteger();
            } else {
                vector<NestedInteger> cur = vi[idx].getList();
                nlist.push_back(make_pair(cur, 0));
            }
        }
    }

    bool hasNext() {
        while(true) {
            if (nlist.empty()) break;
            pair<vector<NestedInteger>, int>& top = nlist.back();
            int idx = top.second;
            vector<NestedInteger> vi = top.first;
            if (idx >= vi.size()) nlist.pop_back();
            else break;
        }
        return nlist.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
