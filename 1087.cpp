class Solution {
public:
    vector<string> expand(string S) {
      bool found = false;
      for (int i = 0; i < S.size(); ++i) {
          if (S[i] >= 'a' && S[i] <= 'z') continue;
          found = true;
      }
      if (!found) return {S};
      int cnt=0;
      int n = S.size();
      int i;
      for (i = 0; i < n; ++i) {
          if (S[i] == '{') cnt++;
          else if (S[i] == '}') cnt--;
          if (cnt == 0) break;
      }
      if (S[n-1] == '}' && i == n-1) {
          return expand(S.substr(1, n-2));
      }
      vector<string> ss;
      cnt=0;
      string st;
      for (int i = 0; i < n; ++i) {
        st.push_back(S[i]);
        if (S[i] == '{') cnt++;
        else if (S[i] == '}') cnt--;
        if (S[i] == ',' && !cnt) {
          st.pop_back();
          ss.push_back(st);
          st.clear();
        }
      }
      if (st.size() > 0) ss.push_back(st);
      if (ss.size() == 1) {
        vector<string> ss2;
        st.clear();
        cnt=0;
        for (int i = 0; i < n; ++i) {
          if (S[i] == '{') {
            if (cnt == 0 && st.size() > 0) {
              ss2.push_back(st);
              st.clear();
            }
            cnt++;
            st.push_back(S[i]);
          } else if (S[i] == '}') {
            st.push_back(S[i]);
            cnt--;
            if (cnt == 0 && st.size() > 0) {
              ss2.push_back(st);
              st.clear();
            }
          } else {
            st.push_back(S[i]);
          }
        }
        if (cnt == 0 && st.size() > 0) {
          ss2.push_back(st);
        }
        vector<string> ans = expand(ss2[0]);
        for (int i = 1; i < ss2.size(); ++i) {
          auto res  =expand(ss2[i]);
          vector<string> ans2;
          for (auto s1 : ans) {
            for (auto s2 : res) {
              ans2.push_back(s1 + s2);
            }
          }
          ans = ans2;
        }
        return ans;
      } else {
        set<string> res;
        for (int i = 0; i < ss.size(); ++i) {
          auto res2 = expand(ss[i]);
          for (auto s : res2) {
              res.insert(s);
          }
        }
        return vector<string>(res.begin(), res.end());
      }
      return {};
    }
};
