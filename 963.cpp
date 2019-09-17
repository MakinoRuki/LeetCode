#define mp make_pair
class Solution {
public:
    double sqr(double x) {return x*x;}
    double getarea(int a, int c, int b, vector<vector<int>>& pts) {
      double d1 = sqrt(sqr(pts[a][0]-pts[c][0]) + sqr(pts[a][1]-pts[c][1]));
      double d2 = sqrt(sqr(pts[b][0]-pts[c][0]) + sqr(pts[b][1]-pts[c][1]));
      return d1 * d2;
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
      double ans = -1;
      map<pair<int, pair<int, int> >, vector<pair<int, int> > > mm;
      int n = points.size();
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          int x1 = points[i][0];
          int y1 = points[i][1];
          int x2 = points[j][0];
          int y2 = points[j][1];
          int d = sqr(x1-x2)+sqr(y1-y2);
          int x0 = (x1+x2);
          int y0=(y1+y2);
          mm[mp(d, mp(x0, y0))].push_back(mp(i, j));
        }
      }
      for (auto v1 : mm) {
        auto v2 = v1.second;
        for (int i = 0; i < v2.size(); ++i) {
          for (int j = i + 1; j < v2.size(); ++j) {
            int a = v2[i].first;
            int b = v2[i].second;
            int c = v2[j].first;
            int d = v2[j].second;
            if (a != c && a != d && b != c && b != d) {
              double res = getarea(a, c, b, points);
              if (ans < 0) ans = res;
              else ans = min(ans, res);
            }
          }
        }
      }
      return (ans < 0 ? 0 : ans);
    }
};
