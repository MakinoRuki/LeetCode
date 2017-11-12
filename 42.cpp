class Solution {
public:
    int trap(int A[], int n) {
        int lft[n+2];
        int rit[n+2];
        lft[0]=A[0];
        for(int i=1;i<n;++i){
            lft[i] = max(lft[i-1], A[i]);
        }
        rit[n-1]=A[n-1];
        for(int i=n-2;i>=0;--i){
            rit[i] = max(rit[i+1], A[i]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans += min(lft[i], rit[i])-A[i];
        }
        return ans;
    }
};
