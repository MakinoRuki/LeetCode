class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int cnt = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0){
                if (A[i] >= B[j]) {
                    A[cnt--] = A[i--];
                } else {
                    A[cnt--] = B[j--];
                }
            } else {
                if (i >= 0) {
                    A[cnt--] = A[i--];
                }
                if (j >= 0) {
                    A[cnt--] = B[j--];
                }
            }
        }
    }
};
