class Solution {
public:
    string baseNeg2(int N) {
        string res = "";
        while(N) {
            if (N & 1) res = "1" + res;
            else res = "0" + res;
            N = -(N >> 1);
        }
        return res;
    }
};
