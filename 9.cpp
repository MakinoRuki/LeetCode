class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int cnt = 0;
        int y = x;
        while(y) {
            cnt++;
            y /= 10;
        }
        int pw = 1;
        for (int i = 1; i < cnt; ++i) {
            pw *= 10;
        }
        int l = pw, r = 1;
        while(l > r) {
            int ln = x / l % 10;
            int rn = x / r % 10;
            if (ln != rn) return false;
            l /= 10;
            r *= 10;
        }
        return true;
    }
};
