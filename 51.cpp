class Solution {
public:
    vector<vector<string> >ans;
    void getAnswer(vector<int>& res, int n){
        vector<string>tmp;
        tmp.clear();
        for(int i=0;i<n;++i){
            string row="";
            for(int j=0;j<n;++j){
                if(j==res[i]){
                    row+="Q";
                }else row+=".";
            }
            tmp.push_back(row);
        }
        ans.push_back(tmp);
    }
    void dfs(int cur, vector<int>&res, int n){
        if(cur==n){
            getAnswer(res, n);
            return ;
        }
        for(int i=0;i<n;++i){
            bool ok=true;
            for(int j=0;j<cur;++j){
                if(res[j] == i){
                    ok=false;
                }else if(res[j] +j ==i+cur){
                    ok=false;
                }else if(res[j]-j == i-cur){
                    ok=false;
                }
            }
            if(ok){
                res.push_back(i);
                dfs(cur+1, res, n);
                res.pop_back();
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<int>res;
        res.clear();
        ans.clear();
        if(!n)return ans;
        dfs(0, res, n);
        return ans;
    }
};
