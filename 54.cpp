class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        ans.clear();
        int n = matrix.size();
        if (n == 0) return ans;
        if (n == 1) return matrix[0];
        int m = matrix[0].size();
        int u = -1, d = n, l = -1, r = m;
        int s = 0;
        int i = 0, j = 0;
        int cnt = 0;
        while(true) {
            cnt++;
            if (cnt == n * m + 1) break;
            ans.push_back(matrix[i][j]);
            if (s == 0) {
                if (j + 1 < r) {
                    j++;
                } else {
                    i++;
                    s = 1;
                }
            } else if (s == 1) {
                if (i + 1 < d) {
                    i++;
                } else {
                    j--;
                    s = 2;
                }
            } else if (s == 2) {
                if (j - 1 > l) {
                    j--;
                } else {
                    i--;
                    s = 3;
                }
            } else if (s == 3) {
                if (i - 1 > u + 1) {
                    i--;
                } else {
                    j++;
                    s = 0;
                    u++;
                    d--;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};
