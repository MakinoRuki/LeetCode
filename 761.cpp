class Solution {
public:
    string makeLargestSpecial(string S) {
        int n = S.size();
        int cnt = 0;
        int st = 0;
        vector<string> rks;
        rks.clear();
        for (int i = 0; i < n; ++i) {
            if (S[i] == '1')cnt++;
            else cnt--;
            if (cnt == 0) {
                rks.push_back("1" + makeLargestSpecial(S.substr(st + 1, i - st - 1)) + "0");
                st = i + 1;
            }
        }
        sort(rks.begin(), rks.end());
        string ans = "";
        for (int i = rks.size() - 1; i >= 0; --i) {
            ans += rks[i];
        }
        return ans;
    }
};
