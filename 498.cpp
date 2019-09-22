class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();
        int x = 0;
        int y = 0;
        bool up = true;
        while(res.size() < n * m) {
            res.push_back(matrix[x][y]);
            if (up) {
                int nx=x-1;
                int ny = y+1;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    x = nx;
                    y= ny;
                } else {
                    nx = x;
                    ny = y+1;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        x = nx;
                        y = ny;
                    } else {
                        x++;
                    }
                    up = !up;
                }
            } else {
                int nx = x+1;
                int ny = y-1;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    x = nx;
                    y = ny;
                } else {
                    nx = x+1;
                    ny = y;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        x = nx;
                        y = ny;
                    } else {
                        y++;
                    }
                    up = !up;
                }
            }
        }
        return res;
    }
};
