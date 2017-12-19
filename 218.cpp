#define mp make_pair
#define pii pair<int, int>
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pii> ans;
        ans.clear();
        int n = buildings.size();
        vector<pair<pii, int> > rank;
        rank.clear();
        set<pii> heights;
        int preh = 0;
        heights.clear();
        for (int i = 0; i < n; ++i) {
            rank.push_back(mp(mp(buildings[i][0], -1), i));
            rank.push_back(mp(mp(buildings[i][1], 1), i));
        }
        sort(rank.begin(), rank.end());
        for (int i = 0; i < rank.size(); ++i) {
            int j;
            for (j = i; j < rank.size() && (rank[j].first.first == rank[i].first.first); ++j) {
                int x = rank[j].first.first;
                int f = rank[j].first.second;
                int idx = rank[j].second;
                if (f == -1) {
                    heights.insert(mp(-buildings[idx][2], idx));
                } else {
                    heights.erase(mp(-buildings[idx][2], idx));
                }
            }
            i = j - 1;
            if (heights.empty()) {
                if (preh != 0) {
                    ans.push_back(mp(rank[i].first.first, 0));
                    preh = 0;
                }
            } else {
                pii top = *heights.begin();
                if (-top.first != preh) {
                    ans.push_back(mp(rank[i].first.first, -top.first));
                    preh = -top.first;
                }
            }
        }
        return ans;
    }
};
