class Solution {
public:
    string dfs(string& st, unordered_set<string>& vis, int tot, int n, int k) {
      if (vis.size() == tot) {
        return st;
      }
      for (char a = '0'; a < '0' + k; ++a) {
        string s = st.substr(st.size()-n+1);
        s.push_back(a);
        if (vis.find(s) == vis.end()) {
          vis.insert(s);
          st.push_back(a);
          auto res2 = dfs(st, vis, tot, n, k);
          if (!res2.empty()) return res2;
          vis.erase(s);
          st.pop_back();
        }
      }
      return "";
    }

    string crackSafe(int n, int k) {
      string ans;
      int tot=1;
      for (int i = 1; i <= n; ++i) {
        tot *= k;
      }
      unordered_set<string> vis;
      string st(n, '0');
      vis.insert(st);
      string res= dfs(st, vis, tot, n, k);
      return res;
    }
};
