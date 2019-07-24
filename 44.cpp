class Solution {
public:
    int n, m;
    int star, stari;
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        star = -1;
        stari = -1;
        int i = 0, j = 0;
        while(i < n) {
            if (s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            } else {
                if (p[j] == '*') {
                    star = j;
                    stari = i;
                    j++;
                } else {
                    if (star < 0) return false;
                    i = stari + 1;
                    j = star + 1;
                    stari = i;
                }
            }
        }
        while(j < m) {
            if (p[j] != '*') return false;
            j++;
        }
        return true;
    }
};
