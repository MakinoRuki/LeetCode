// 如果是I就顺着放，否则就一串D来倒序。
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans;
        ans.clear();
        int n = s.size();
        ans.push_back(1);
        int i = 0;
        while(i < n) {
            if (s[i] == 'I') {
                ans.push_back(i + 1 + 1);
                i++;
            } else {
                int j = i;
                while(j < n && s[j] != 'I') j++;
                int det = j - i;
                int r = ans.back() + det;
                int l = ans.back();
                ans.pop_back();
                for (int k = r; k >= l; --k) {
                    ans.push_back(k);
                }
                i = j;
            }
        }
        return ans;
    }
};
