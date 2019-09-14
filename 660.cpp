// 遇到9就进位，相当于转换成9进制。
class Solution {
public:
    int newInteger(int n) {
      vector<int> res;
      while(n) {
        res.push_back(n%9);
        n/=9;
      }
      int ans=0;
      for (int i = res.size()-1; i>=0; --i) {
        ans= ans*10 + res[i];
      }
      return ans;
    }
};
