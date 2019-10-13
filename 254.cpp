class Solution {
public:
    void dfs(int n, int st, vector<int>& cur, vector<vector<int>>& ans) {
        if (n == 1) {
            if (cur.size()) ans.push_back(cur);
            return;
        }
        if (n >= st && cur.size()) {
            cur.push_back(n);
            dfs(n/n, n, cur, ans);
            cur.pop_back();
        }
        for (int i = st; i*i <= n; ++i) {
            if (n%i==0) {
                cur.push_back(i);
                dfs(n/i, i, cur, ans);
                cur.pop_back();
            }
        }
    } 
    vector<vector<int>> getFactors(int n) {
        if (n==1) return {};
        int i;
        for (i = 2; i *i <= n; ++i) {
            if (n%i == 0) break;
        }
        if (i*i > n) return {};
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(n, 2, cur, ans);
        return ans;
    }
};
