class Solution {
public:
    vector<int> dfs(vector<char>& os, int ob, int oe, vector<int>& nums, int nb, int ne) {
        if (ob >= oe) {
            return {nums[nb]};
        } else {
            vector<int> ans;
            ans.clear();
            for (int i = ob; i < oe; ++i) {
                vector<int> res1 = dfs(os, ob, i, nums, nb, i + 1);
                vector<int> res2 = dfs(os, i + 1, oe, nums, i + 1, ne);
                for (int r1 = 0; r1 < res1.size(); ++r1) {
                    for (int r2 = 0; r2 < res2.size(); ++r2) {
                        if (os[i] == '+') ans.push_back(res1[r1] + res2[r2]);
                        else if (os[i] == '-') ans.push_back(res1[r1] - res2[r2]);
                        else if (os[i] == '*') ans.push_back(res1[r1] * res2[r2]);
                        else ans.push_back(res1[r1] / res2[r2]);
                    }
                }
            }
            // if (ob == 0 && oe == 1 && nb == 0 && ne == 2) {
            //     cout<<ans.size()<<" "<<ans[0]<<endl;
            // }
            return ans;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        vector<char> os;
        vector<int> nums;
        int n = input.size();
        int sum = 0;
        bool has = false;
        for (int i = 0; i < n; ++i) {
            if (input[i] >= '0' && input[i] <= '9') {
                sum = sum * 10 + input[i] - '0';
                has = true;
            } else {
                if (has) {
                    nums.push_back(sum);
                    sum = 0;
                    has = false;
                }
                os.push_back(input[i]);
            }
        }
        if (has) {
            nums.push_back(sum);
        }
        return dfs(os, 0, os.size(), nums, 0, nums.size());
    }
};
