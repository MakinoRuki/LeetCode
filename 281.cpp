// 按层遍历用queue。
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size()) q.push(make_pair(v1.begin(), v1.end()));
        if (v2.size()) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto cur = q.front();
        q.pop();
        int v = (*cur.first);
        cur.first++;
        if (cur.first != cur.second) {
            q.push(cur);
        }
        return v;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
