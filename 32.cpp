class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> stack;
        stack.clear();
        int ans = 0;
        int accu = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                if (stack.size() > 0) {
                    int tmp = stack.back();
                    stack.pop_back();
                    if (stack.size() == 0) {
                        accu += i - tmp + 1;
                        ans = max(ans, accu);
                    } else {
                        ans = max(ans, i - stack.back());
                    }
                } else {
                    accu = 0;
                }
            }
        }
        return ans;
    }
};
