class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n=num.size();
        if(!n)return ;
        int i=n-1;
        for(i=n-1;i>0;--i){
            if(num[i] > num[i-1]){
                break;
            }
        }
        if(i==0){
            sort(num.begin(), num.end());
            return ;
        }
        i--;
        int j;
        for(j = n-1; j>i; --j){
            if(num[j] > num[i]){
                break;
            }
        }
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.begin()+n);
        return;
    }
};
