class Solution {
public:
    void sortColors(int A[], int n) {
        if(n==0)return ;
        int lft=-1;
        int rit=n;
        for(int i=0;i<min(n,rit);){
            if(A[i]==0){
                if(i==lft+1){
                    lft++;
                    i++;
                }else{
                    swap(A[lft+1],A[i]);
                    lft++;
                }
            }else if(A[i]==2){
                if(i==rit-1){
                    rit--;
                    i++;
                }else{
                    swap(A[rit-1],A[i]);
                    rit--;
                }
            }else i++;
        }
    }
};
