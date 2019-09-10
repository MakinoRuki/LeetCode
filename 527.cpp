class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
      int n = dict.size();
      vector<string> res;
      int pre[n+2];
      for (int i = 0; i < n; ++i) {
        string s;
        s.push_back(dict[i][0]);
        pre[i] = 1;
        if (dict[i].size() > 3) {
          s += to_string(dict[i].size() - 2);
        } else {
          s += dict[i].substr(pre[i], 1);
        }
        if (dict[i].size() > 2) {
          s.push_back(dict[i][dict[i].size()-1]);
        }
        res.push_back(s);
      }
      for (int i = 0; i < n; ++i) {
     //   cout<<i<<" "<<res[i]<<endl;
        while(true) {
          vector<int> idx;
          idx.clear();
          for (int j = i + 1; j < n; ++j) {
            //cout<<j<<" "<<res[j]<<" "<<(res[i] == res[j])<<endl;
            if (res[i] == res[j]) {
              idx.push_back(j);
            }
          }
          if (idx.empty()) {
            break;
          }
          if (pre[i] >= (int)dict[i].size() - 2) {
            break;
          }
          idx.push_back(i);
        //  cout<<i<<" "<<idx.size()<<endl;
          for (int j = 0; j < (int)idx.size(); ++j) {
            int id = idx[j];
            pre[id]++;
            string s;
            s = dict[id].substr(0, pre[id]);
            if (pre[id] + 2 < (int)dict[id].size()) {
              s += to_string(dict[id].size() - 1 - pre[id]);
            } else {
              s += dict[id].substr(pre[id], 1);
            }
            s.push_back(dict[id][dict[id].size()-1]);
            res[id] = s;
          }
        }
      }
      return res;
    }
};
