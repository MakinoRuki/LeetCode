class Solution {
public:
    void dfs(string s, string low, string high, int& ans) {
      if (s.size() > high.size()) return;
      if (s.size() >= low.size() && s.size() <= high.size()) {
        if (!(s.size() == high.size() && s.compare(high)>0)) {
          if (!(s.size() > 1 && s[0] == '0')) {
            if (!(s.size() == low.size() && s.compare(low)<0)) {
            //  cout<<"s="<<s<<endl;
              ans++;
            }
          }
        }
      }
      dfs("0"+s+"0", low, high, ans);
      dfs("1"+s+"1", low, high, ans);
      dfs("8"+s+"8", low, high, ans);
      dfs("6"+s+"9", low, high, ans);
      dfs("9"+s+"6", low, high, ans);
    }

    int strobogrammaticInRange(string low, string high) {
      int ans=0;
      dfs("", low, high, ans);
      dfs("0", low, high, ans);
      dfs("1", low, high, ans);
      dfs("8", low, high, ans);
      return ans;
    }
};
