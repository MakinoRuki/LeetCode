class Solution {
public:
    unordered_map<int, int> debt;
    int n;
    int ans = INT_MAX;
    void dfs(int cur, vector<int>& rems, int sum) {
        while(cur < rems.size() && rems[cur] == 0) cur++;
        if (cur == rems.size()) {
            ans = min(ans, sum);
            return;
        }
        for (int i = cur + 1; i < rems.size(); ++i) {
            if ((rems[cur] > 0 && rems[i] < 0) || (rems[cur] < 0 && rems[i] > 0)) {
                rems[i] += rems[cur];
                dfs(cur+1, rems, sum+1);
                rems[i] -= rems[cur];
            }
        }
    }
    int minTransfers(vector<vector<int>>& ts) {
        debt.clear();
        n = ts.size();
        if (n == 0) return 0;
        debt.clear();
        for (int i = 0; i < n; ++i) {
            debt[ts[i][0]] -= ts[i][2];
            debt[ts[i][1]] += ts[i][2];
        }
        vector<int> rems;
        rems.clear();
        for (auto d : debt) {
            if (d.second) rems.push_back(d.second);
        }
        dfs(0, rems, 0);
        return ans;
    }
};
