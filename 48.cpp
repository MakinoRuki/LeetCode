class Solution {
public:
    int n;
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        if(!n)return ;
        int side=n;
        for(int i=0;i<(n+1)/2;++i){
            if(side==1){
                break;
            }
            for(int j=0;j<side-1;++j){
                int tmp=matrix[n-1-i-j][i];
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = matrix[i][i+j];
                matrix[i][i+j]=tmp;
            }
            side-=2;
        }
        return ;
    }
};
