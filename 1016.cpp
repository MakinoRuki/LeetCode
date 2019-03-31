class Solution {
public:
    int n;
    bool queryString(string S, int N) {
        n = S.size();
         set<long long> ss;
         for (int i = 0; i < n; ++i) {
             long long res = S[i] - '0';
             ss.insert(res);
             for (int j = i + 1; j <= i + 32 && j < S.size(); ++j) {
                res = res * 2 + S[j] - '0';
                ss.insert(res);
            }
         }
        if (N > ss.size()) return false;
        for (int i = 1; i <= N; ++i) {
            if (ss.find(i) == ss.end()) return false;
         }
        return true;
    }
};
