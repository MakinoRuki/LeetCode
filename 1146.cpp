class SnapshotArray {
public:
    unordered_map<int, vector<int> > ks;
    unordered_map<int, vector<int> > kv;
    int snap_id=0;
    SnapshotArray(int length) {
        for (int i = 0; i < length; ++i) {
            ks[i].push_back(0);
            kv[i].push_back(0);
        }
    }
    
    void set(int index, int val) {
        //  跟上次值相等就不用再存了。
        if (kv[index].back() != val) {
            ks[index].push_back(snap_id);
            kv[index].push_back(val);
        }
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto ss = ks[index];
        int idx = upper_bound(ss.begin(), ss.end(), snap_id) - ss.begin();
        idx--;
        return kv[index][idx];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
