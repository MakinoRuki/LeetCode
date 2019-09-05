class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> rk;
        rk.push_back(a);
        rk.push_back(b);
        rk.push_back(c);
        vector<int> res;
        sort(rk.begin(), rk.end());
        if (rk[0]+1==rk[1] && rk[1]+1==rk[2]) {
            res.push_back(0);
        } else {
            if (rk[0]+2>=rk[1] || rk[1]+2>=rk[2]) {
                res.push_back(1);
            } else {
                res.push_back(2);
            }
        }
        res.push_back(rk[1]-rk[0]-1+rk[2]-rk[1]-1);
        return res;
    }
};
