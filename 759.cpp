/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
struct node {
    int b,e;
    int i,j;
    bool operator < (const node& x) const {
        if (b == x.b) {
            return e > x.e;
        }
        return b > x.b;
    }
};
// O(C*log(N)) + O(N)
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        int n = schedule.size();
        for (int i = 0; i < n; ++i) {
            node cur;
            cur.b = schedule[i][0]->start;
            cur.e = schedule[i][0]->end;
            cur.i = i;
            cur.j = 0;
            pq.push(cur);
        }
        int cnt=0;
        int b = INT_MIN;
        int e = INT_MIN;
        vector<Interval*> ans;
        while(!pq.empty()) {
            int tb = pq.top().b;
            int te = pq.top().e;
            while(!pq.empty()) {
                auto top = pq.top();
                if (top.b <= te && top.e >= tb) {
                    tb = min(tb, top.b);
                    te = max(te, top.e);
                    int i = top.i;
                    int j = top.j;
                    j++;
                    pq.pop();
                    if (j < schedule[i].size()) {
                        top.b = schedule[i][j]->start;
                        top.e = schedule[i][j]->end;
                        top.j++;
                        pq.push(top);
                    }
                } else {
                    break;
                }
            }
            cnt++;
            if (cnt == 1) {
                b = tb;
                e = te;
            } else {
                if (tb > e) {
                    ans.push_back(new Interval(e, tb));
                }
                b = tb;
                e = te;
            }
        }
        return ans;
    }
private:
    priority_queue<node> pq;
};
// O(C*log(C)) + O(C)
// class Solution {
// public:
//     vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
//         vector<pair<int, int>> rk;
//         int n = schedule.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < schedule[i].size(); ++j) {
//                 int st = schedule[i][j]->start;
//                 int et = schedule[i][j]->end;
//                 rk.push_back(make_pair(st, 1));
//                 rk.push_back(make_pair(et, -1));
//             }
//         }
//         sort(rk.begin(), rk.end());
//         int e = INT_MIN;
//         int b = INT_MIN;
//         int cnt=0;
//         vector<Interval*> ans;
//         for (int i = 0; i < rk.size(); ++i) {
//             int t = rk[i].first;
//             int f = rk[i].second;
//             cnt += f;
//             if (f < 0 && cnt == 0) {
//                 b = t;
//                 e = t;
//             } else {
//                 if (f > 0 && cnt == 1) {
//                     if (t > e && b != INT_MIN) {
//                         e =  t;
//                         ans.push_back(new Interval(b, e));
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
