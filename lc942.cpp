/* Solution 1: */
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> tmp;
        tmp.clear();
        for (int i = 0; i <= n; ++i) {
            tmp.push_back(i);
        }
        vector<int> ans;
        ans.clear();
        for (int i = 0; i < n; ++i) {
           if (S[i] == 'D') {
               int j;
               for (j = i; j < n; ++j) {
                   if (S[j] != 'D') break;
               }
               for (int k = j; k >= i; --k) {
                   ans.push_back(tmp[k]);
               }
               i = j;
           }  else {
               ans.push_back(tmp[i]);
           }
        }
        if (ans.size() < tmp.size()) ans.push_back(tmp.back());
        return ans;
    }
};

/* Solution 2: */
/* class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') ans.push_back(i+1);
            else {
                int j;
                for (j = i; j >= 0; --j) {
                    if (S[j] == 'I') break;
                }
                ans.insert(ans.begin()+j+1, i+1);
            }
        }
        return ans;
    }
}; */
