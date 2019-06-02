class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        ans.clear();
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int add = 0;
        int sign = 1;
        for (int i = 0; i < max(arr1.size(), arr2.size()); ++i) {
            int a1 = i < arr1.size() ? sign * arr1[i] : 0;
            int a2 = i < arr2.size() ? sign * arr2[i] : 0;
            int sum = a1 + a2 + add;
            int a3 = (sum % 2) ? 1 : 0;
            ans.push_back(a3);
            sum -= sign * a3;
            add = sum / 2;
            sign = -sign;
        }
        if (add) {
            if (add % 2) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};
