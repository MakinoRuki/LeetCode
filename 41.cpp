class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(!n)return 1;
        for(int i=0;i<n;++i){
            while(A[i] >=1 && A[i]<=n && A[i]!=i+1){
                if(A[A[i]-1]==A[i])
                    break;
                swap(A[A[i]-1], A[i]);
            }
        }
        for(int i=0;i<n;++i){
            if(A[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
