class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int> > rk;
        rk.clear();
        for (int i = 0; i < n; ++i) {
            rk.push_back(make_pair(points[i][0], points[i][1]));
        }
        sort(rk.begin(), rk.end());
        int i = 0;
        int cnt = 0;
        while(i < n) {
            int j = i;
            int b = rk[i].first;
            int e = rk[i].second;
            while(j < n) {
                if (rk[j].first <= e && rk[j].second >= b) {
                    b = max(b, rk[j].first);
                    e = min(e, rk[j].second);
                    j++;
                } else {
                    break;
                }
            }
            cnt++;
            i = j;
        }
        return cnt;
    }
};
