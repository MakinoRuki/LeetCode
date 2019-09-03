// 步数是固定增加1的，每两个相同。
class Solution {
public:
    int dc[4] = {1, 0, -1, 0};
    int dr[4] = {0, 1, 0, -1};
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int> > ans;
        ans.push_back({r0, c0});
        int s = 1;
        int cd = 0;
        while(ans.size() < R*C) {
            for (int i = 0; i < s; ++i) {
                r0 += dr[cd];
                c0 += dc[cd];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    ans.push_back({r0, c0});
                }
            }
            cd = (cd + 1) % 4;
            for (int i = 0; i < s; ++i) {
                r0 += dr[cd];
                c0 += dc[cd];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    ans.push_back({r0, c0});
                }
            }
            cd = (cd + 1) % 4;
            s++;
        }
        return ans;
    }
};
