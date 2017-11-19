class Solution {
public:
    vector<vector<int> >ans;
    int n;
    vector<int>S;
    void dfs(int cur, vector<int>&res){
        ans.push_back(res);
        for(int i=cur;i<n;++i){
            // 相等的就跳过，防止duplicate。
            if(i>cur && S[i]==S[i-1])
                continue;
            res.push_back(S[i]);
            dfs(i+1, res);
            res.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &_S) {
       S = _S;
       n=S.size();
       ans.clear();
       sort(S.begin(), S.end());
       vector<int>res;
       res.clear();
       dfs(0,res);
       return ans;
    }
};
