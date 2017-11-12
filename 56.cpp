/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// struct cmp {
//   bool operator()(const Interval& a, const Interval& b) {
//       if (a.start == b.start) {
//           return a.end < b.end;
//       }
//       return a.start < b.start;
//   }  
// };
bool cmp (const Interval& a, const Interval& b) {
   if (a.start == b.start) {
          return a.end < b.end;
      }
      return a.start < b.start;
}
bool overlap (const Interval& a, const Interval& b) {
    return (a.start <= b.end && a.end >= b.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<pair<int, int> > rank;
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int i = 0;
        while(i < n) {
            Interval tmp = intervals[i];
            while(i + 1 < n && overlap(tmp, intervals[i + 1])) {
                tmp.start = min(tmp.start, intervals[i + 1].start);
                tmp.end = max(tmp.end, intervals[i + 1].end);
                i++;
            }
            i++;
            ans.push_back(tmp);
        }
        return ans;
    }
};
