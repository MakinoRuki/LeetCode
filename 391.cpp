class Solution {
public:
    unordered_map<int, int> apps;
    int gethash(int x, int y) {
        return x * 10000000 + y;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<vector<int> > rec = rectangles;
        int n = rectangles.size();
        int u = INT_MIN, d = INT_MAX, l = INT_MAX, r = INT_MIN;
        apps.clear();
        int s = 0, ts = 0;
        for (int i = 0; i < n; ++i) {
            int li = rec[i][0];
            int di = rec[i][1];
            int ri = rec[i][2];
            int ui = rec[i][3];
            apps[gethash(li, ui)]++;
            apps[gethash(li, di)]++;
            apps[gethash(ri, ui)]++;
            apps[gethash(ri, di)]++;
            u = max(u, ui);
            d = min(d, di);
            l = min(l, li);
            r = max(r, ri);
            s += abs(ui - di) * abs(ri - li);
        }
        if (apps[gethash(l, u)] != 1) return false;
        apps.erase(gethash(l, u));
        if (apps[gethash(l, d)] != 1) return false;
        apps.erase(gethash(l, d));
        if (apps[gethash(r, u)] != 1) return false;
        apps.erase(gethash(r, u));
        if (apps[gethash(r, d)] != 1) return false;
        apps.erase(gethash(r, d));
        for (auto x : apps) {
            if (x.second != 2) return false;
        }
        ts = abs(u - d) * abs(r - l);
        if (ts != s) return false;
        return true;
    }
};
