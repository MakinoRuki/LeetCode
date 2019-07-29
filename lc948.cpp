// 把token排序然后能换成score就换成score。power不够了就用score换最大的token的power。
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        int pts = 0;
        int r = n-1;
        int ans = 0;
        sort(tokens.begin(), tokens.end());
        for (int i = 0; i <= r; ++i) {
            if (P >= tokens[i]) {
                P -= tokens[i];
                pts++;
            } else {
                while(pts > 0 && r > i) {
                    pts--;
                    P += tokens[r--];
                    if (P >= tokens[i]) break;
                }
                if (r > i && P >= tokens[i]) {
                    P -= tokens[i];
                    pts++;
                } else {
                    break;
                }
            }
            ans = max(ans, pts);
        }
        ans = max(ans, pts);
        return ans;
    }
};
