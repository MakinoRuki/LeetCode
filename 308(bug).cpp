class NumMatrix {
public:
    int BIT[100][100];
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
        memset(BIT, 0, sizeof(BIT));
        n = matrix.size();
        if (n > 0) {
            m = matrix[0].size();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    update(i, j, matrix[i][j]);
                }
            }
        }
    }
    
    void update(int row, int col, int val) {
        row++;
        col++;
        while(row <= n) {
            while(col <= m) {
                BIT[row][col] += val;
                col += (col&(-col));
            }
            row += (row&(-row));
        }
    }
    
    int sum(int row, int col) {
        int res = 0;
        while(row > 0) {
            while(col > 0) {
                res += BIT[row][col];
                col -= (col&(-col));
            }
            row -= (row&(-row));
        }
        return res;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2+1, col2+1) - sum(row1, col2+1) - sum(row2+1, col1) + sum(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
