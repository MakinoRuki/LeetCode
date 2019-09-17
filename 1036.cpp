// 200个block围起来的墙最多n*n/2个格子。因此搜到大于这么多就是没有被围住了。

#define mp make_pair
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool check(vector<vector<int>>& b, vector<int>& s, vector<int>& t) {
      int cnt=0;
      int n = b.size();
      queue<pair<int,int>> q;
      q.push(make_pair(s[0], s[1]));
      set<pair<int,int>> ss;
      for (int i = 0; i < n; ++i) {
        ss.insert(mp(b[i][0], b[i][1]));
      }
      set<pair<int,int>> vis;
      vis.insert(mp(s[0], s[1]));
      while(!q.empty()) {
        auto top= q.front();
        q.pop();
        cnt++;
        if (cnt>n*n/2) break;
        if (top.first==t[0] && top.second==t[1]) return true;
        int x=top.first;
        int y=top.second;
        for (int d=0; d<4; ++d) {
          int nx=x+dx[d];
          int ny=y+dy[d];
          if (nx>=0 && nx < 1000000 && ny>=0 && ny < 1000000) {
            if (vis.find(mp(nx,ny))==vis.end() && ss.find(mp(nx,ny))==ss.end()) {
              q.push(mp(nx, ny));
              vis.insert(mp(nx,ny));
            }
          }
        }
      }
      return cnt>n*n/2;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>&s, vector<int>& t) {
      if (check(blocked, s, t) && check(blocked, t, s)) return true;
      return false;
    }
};
