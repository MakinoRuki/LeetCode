class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0; i <= 30; ++i) {
            if (m == 0 && n == 0) break;
            if (n == m && (n % 2)) {
                ans |= (1<<i);
            }
            m /= 2;
            n /= 2;
        }
        return ans;
    }
};
