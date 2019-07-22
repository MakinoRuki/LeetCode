// should be O(n+m) as row and col are independent.
class Solution {
public:
    int n,m;
    int ans;
    int rn[1000], cn[1000];
    int minTotalDistance(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0 || grid[0].size() == 0) return 0;
        m = grid[0].size();
        ans = 1000000000;
        int rs = 0, cs = 0;
        int l = 0, r = 0, u = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rn[i] += grid[i][j];
                cn[j] += grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                for (int j = 0; j < n; ++j) {
                    rs += (j - i) * rn[j];
                    if (j == i) u += rn[j];
                    else d += rn[j];
                }
            } else {
                rs += u;
                rs -= d;
                u += rn[i];
                d -= rn[i];
            }
            cs = 0;
            l = 0, r = 0;
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    for (int k = 0; k < m; ++k) {
                        cs += (k - j) * cn[k];
                        if (k == j) l += cn[k];
                        else r += cn[k];
                    }
                } else {
                    cs += l;
                    cs -= r;
                    l += cn[j];
                    r -= cn[j];
                }
                ans = min(ans, cs + rs);
            }
        }
        return ans;
    }
};
