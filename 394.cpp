class Solution {
public:
    string decodeString(string s) {
      int n = s.size();
      vector<string> stk;
      string t;
      bool isnum = false;
      for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
          if (t.size() && !isnum) {
            stk.push_back(t);
            t.clear();
          }
          t.push_back(s[i]);
          isnum = true;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i]>='A' && s[i]<='Z')) {
          t.push_back(s[i]);
          isnum = false;
        } else if (s[i] == '[') {
          if (t.size()) {
            stk.push_back(t);
            t.clear();
          }
          isnum = false;
          stk.push_back(s.substr(i, 1));
        } else {
          if (t.size()) {
            stk.push_back(t);
            t.clear();
          }
          string t2 = stk.back();
          stk.pop_back();
          while(!stk.empty()) {
            if (stk.back() == "[") {
              stk.pop_back();
              string nm = stk.back();
              stk.pop_back();
              string tt;
              for (int j = 0; j < stoi(nm); ++j) {
                tt += t2;
              }
              t2 = tt;
              break;
            } else {
              string tt = stk.back();
              t2 = tt + t2;
              stk.pop_back();
            }
          }
          stk.push_back(t2);
        }
      }
      string ans = "";
      if (t.size()) ans = t;
      while(!stk.empty()) {
        string tt = stk.back();
        stk.pop_back();
        ans = tt + ans;
      }
      return ans;
    }
};
