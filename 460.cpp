class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        int v = cache[key].first;
        int f = cache[key].second;
        freq[f].erase(iters[key]);
        cache[key].second++;
        f++;
        freq[f].push_front(key);
        iters[key] = freq[f].begin();
        if (freq[minf].empty()) minf++;
        return v;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (cache.find(key) != cache.end()) {
            get(key);
            cache[key].first = value;
            return;
        }
        if (cache.size() >= cap) {
            int tkey = freq[minf].back();
            freq[minf].pop_back();
            iters.erase(tkey);
            cache.erase(tkey);
            if (freq[minf].empty()) minf++;
        }
        cache[key] = make_pair(value, 1);
        freq[1].push_front(key);
        iters[key] = freq[1].begin();
        minf = 1;
    }
private:
    int cap;
    int minf;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iters;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
