// 保存一个temp result，可以节约stack的空间。
// +-和*/的区别是，维护当前的tmp变量和tot变量，只有当前是+-时才把tmp合并到tot上。
// 带不带(的区别是，维护变量tot还是入栈。出现(时才入栈。
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<long> stk;
        long tot=0;
        int sign=1;
        long num=0;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num=num*10+s[i]-'0';
            } else {
                if (s[i] == '(') {
                    stk.push_back(tot);
                    stk.push_back(sign);
                    sign = 1;
                    tot=0;
                } else if (s[i] == ')') {
                    tot += sign*num;
                    tot *= stk.back();
                    stk.pop_back();
                    if (!stk.empty()) {
                        tot += stk.back();
                        stk.pop_back();
                    }
                    num=0;
                } else if (s[i] == '+' || s[i] == '-') {
                    tot += sign*num;
                    sign = (s[i] == '+' ? 1: -1);
                    num=0;
                }
            }
        }
        tot += sign*num;
        long res=tot;
        while(!stk.empty()) {
            res += stk.back();
            stk.pop_back();
        }
        return res;
    }
};
