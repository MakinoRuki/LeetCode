/*先减再乘肯定比先乘再减要更少。因此先乘之后，把det以此换算成乘之前应该减掉的。*/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        int pw = 1;
        while(X < Y) {
            X *= 2;
            ans++;
            pw *= 2;
        }
        int det = X - Y;
        while(det) {
            ans += det / pw;
            det %= pw;
            pw /= 2;
        }
        return ans;
    }
};
