// 3个parts的1的个数必然相等。
#define N 30002
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        int ones[N];
        memset(ones, 0, sizeof(ones));
        ones[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            ones[i] = ones[i + 1] + A[i] - '0';
        }
        if (ones[0] % 3 != 0) return {-1, -1};
        int i0, i1, i2;
        for (i0 = n - 1; i0 >= 0; --i0) {
            if (ones[i0] == ones[0] / 3) break;
        }
        for (i1 = i0 - 1; i1 >= 0; --i1) {
            if (ones[i1] == ones[0] / 3) break;
        }
        for (i2 = i1 - 1; i2 >= 0; --i2) {
            if (ones[i2] == ones[0] / 3) break;
        }
        int j0 = n - 1, j1 = i0 - 1, j2 = i1 - 1;
        while(true) {
            if (A[j0] == '0') {
                if (A[j1] != '0' || A[j2] != '0') return {-1, -1};
                j0--;
                j1--;
                j2--;
            } else {
                break;
            }
        }
        while(A[j0]=='0')j0--;
        while(A[j1]=='0')j1--;
        while(A[j2]=='0')j2--;
        while(j0 >= i0 && j1 >= i1 && j2 >= i2) {
            if (A[j0] != A[j1] || A[j1] != A[j2] || A[j0] != A[j2]) break;
            j0--;
            j1--;
            j2--;
        }
        return {i2 + n - i0 - 1, i1 + n - i0};
    }
};
