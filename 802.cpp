class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int deg[n+2];
        memset(deg, 0, sizeof(deg));
        vector<vector<int>> graph2(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                int v  = graph[i][j];
                graph2[v].push_back(i);
                deg[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
          //  cout<<u<<endl;
            for (int i = 0; i < graph2[u].size(); ++i) {
                int v = graph2[u][i];
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
