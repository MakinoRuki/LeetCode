class Solution {
public:
    int n;
    int maxProfit(vector<int> &prices) {
        n=prices.size();
        int ans=0;
        for(int i=0;i<n-1;++i){
            int delta=-prices[i]+prices[i+1];
            if(delta>=0)
                ans+=delta;
        }
        return ans;
    }
};
