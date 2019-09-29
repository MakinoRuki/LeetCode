// O(1) 用list。

class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mm;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    void put(int key, int val) {
        if (mm.find(key) != mm.end()) {
            auto itr = mm[key];
            cache.erase(itr);
        }
        cache.push_front(make_pair(key, val));
        mm[key] = cache.begin();
        auto t = mm[key];
        if (cache.size() > cap) {
            mm.erase(cache.back().first);
            cache.pop_back();
        }
    }
    int get(int key) {
        if (mm.find(key) == mm.end()) return -1;
        auto tmp = *mm[key];
        cache.erase(mm[key]);
        cache.push_front(tmp);
        mm[key] = cache.begin();
        return tmp.second;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
