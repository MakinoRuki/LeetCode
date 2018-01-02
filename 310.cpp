class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int> > es(n);
        vector<bool> vis(n, false);
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            int a = edges[i].first;
            int b = edges[i].second;
            deg[a]++;
            deg[b]++;
            es[a].push_back(b);
            es[b].push_back(a);
        }
        for (int rem = n; rem > 2;) {
            vector<int> del;
            del.clear();
            for (int i = 0; i < n; ++i) {
                if (deg[i] == 1) {
                    rem--;
                    del.push_back(i);
                    deg[i]--;
                    vis[i] = true;
                }
            }
            for (int i = 0; i < del.size(); ++i) {
                for (int j = 0; j < es[del[i]].size(); ++j) {
                    int v = es[del[i]][j];
                    deg[v]--;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};
