class MyCalendarThree {
public:
    map<int, int> cnt;
    MyCalendarThree() {
        cnt.clear();
    }
    
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int num = 0;
        int ans = 0;
        for (auto x : cnt) {
            num += x.second;
            ans = max(ans, num);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
