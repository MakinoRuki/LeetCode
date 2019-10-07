class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T) return 0;
        queue<int> q;
        q.push(S);
        int dis=0;
        unordered_map<int, unordered_set<int> > bus;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                bus[routes[i][j]].insert(i);
            }
        }
        unordered_set<int> visb;
        unordered_set<int> viss;
        while(!q.empty()) {
            dis++;
            for (int i = q.size()-1; i>= 0; --i) {
                int cur= q.front();
                q.pop();
                auto buses = bus[cur];
                for (auto b : buses) {
                    if (visb.find(b) != visb.end()) continue;
                    for (int j = 0; j < routes[b].size(); ++j) {
                        if (viss.find(routes[b][j]) != viss.end()) continue;
                        if (routes[b][j] == T) return dis;
                        q.push(routes[b][j]);
                        viss.insert(routes[b][j]);
                    }
                }
            }
        }
        return -1;
    }
};
