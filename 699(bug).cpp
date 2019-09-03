class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        int n = positions.size();
        map<int, vector<pair<int, int> > > heights;
        for (int i = 0; i < n; ++i) {
           // cout<<i<<endl;
            int x = positions[i][0];
            int y = x + positions[i][1];
            map<int, int> t;
            int maxh = 0;
            for (auto h : heights) {
                auto vs = h.second;
                for (auto v : vs) {
              //  cout<<"*"<<(*t.begin()).first<<endl;
                    if (h.first > x) {
                        maxh = max(maxh, -(*t.begin()).first);
                    }
                    if (h.first >= y) {
                        break;
                    }
                    int tmp = v.second;
                    if (v.first == -1) {
                       // cout<<"*"<<h.first<<" "<<h.second.first<<" "<<h.second.second<<endl;
                        t[-tmp]++;
                    } else {
                      //  cout<<"*"<<h.first<<" "<<h.second.first<<" "<<h.second.second<<endl;
                        //cout<<"*"<<-tmp<<endl;
                        t[-tmp]--;
                    }
                }
            }
        //    cout<<i<<" "<<maxh<<endl;
            heights[x].push_back(make_pair(-1, maxh + positions[i][1]));
            heights[y].push_back(make_pair(1, maxh + positions[i][1]));
            ans.push_back(0);
            for (auto h : heights) {
                auto vs = h.second;
                for (auto v : vs) {
                    ans.back() = max(ans.back(), v.second);
                }
            }
        }
        return ans;
    }
};
