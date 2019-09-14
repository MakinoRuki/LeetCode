class Solution {
public:
    int dfs(string& expr, unordered_map<string, int>& vals) {
      if (expr[0] != '(') {
        if (expr[0] == '-') {
          return -stoi(expr.substr(1));
        } else if (expr[0] >= '0' && expr[0] <= '9') {
          return stoi(expr);
        } else {
          return vals[expr];
        }
      }
      int n = expr.size();
      expr = expr.substr(1, n-2);
      string t;
      vector<string> res;
      n -= 2;
      int cnt=0;
      for (int i = 0; i < n; ++i) {
        if (expr[i] == ' ') {
          if (!cnt) {
            res.push_back(t);
            t.clear();
          } else {
            t.push_back(expr[i]);
          }
        } else {
          t.push_back(expr[i]);
          if (expr[i] == '(') cnt++;
          else if (expr[i] == ')') cnt--;
        }
      }
      if (t.size()) res.push_back(t);
      if (res[0] == "let") {
        for (int i = 1; i < res.size(); i+=2) {
          if (i + 1 >= res.size()) break;
          string t = res[i+1];
          if (!(t[0] >= '0' && t[0] <= '9')) vals[res[i]] = dfs(res[i+1], vals);
          else vals[res[i]] = (res[i+1][0] == '-' ? -stoi(res[i+1]) : stoi(res[i+1]));
        }
        return dfs(res.back(), vals);
      } else if (res[0] == "mult") {
        unordered_map<string, int> vals2 = vals;
        return dfs(res[1], vals) * dfs(res[2], vals2);
      } else {
        unordered_map<string, int> vals2 = vals;
        return dfs(res[1], vals) + dfs(res[2], vals2);
      }
    }

    int evaluate (string expr) {
      unordered_map<string, int> vals;
      int ans = dfs(expr, vals);
      return ans;
    }
};
