class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rowZero=1;
        int colZero=1;
        int n=matrix.size();
        if(!n)return ;
        int m=matrix[0].size();
        for(int j=0;j<m;++j){
            if(!matrix[0][j]){
                rowZero=0;
            }
        }
        for(int i=0;i<n;++i){
            if(!matrix[i][0]){
                colZero=0;
            }
        }
        for(int i=1;i<n;++i){
            int j;
            for(j=0;j<m;++j){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    break;
                }
            }
        }
        for(int j=1;j<m;++j){
            int i;
            for(i=0;i<n;++i){
                if(!matrix[i][j]){
                    matrix[0][j]=0;
                    break;
                }
            }
        }
        for(int i=1;i<n;++i){
            if(!matrix[i][0]){
                for(int j=0;j<m;++j){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<m;++j){
            if(!matrix[0][j]){
                for(int i=0;i<n;++i){
                    matrix[i][j]=0;
                }
            }
        }
        if(!rowZero){
            for(int j=0;j<m;++j)
                matrix[0][j]=0;
        }
        if(!colZero){
            for(int i=0;i<n;++i)
                matrix[i][0]=0;
        }
    }
};
