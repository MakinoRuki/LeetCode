bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int> > ans;
        ans.clear();
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < n; ++i) {
            ans.insert(ans.begin() + people[i].second, people[i]);
        }
        return ans;
    }
};
