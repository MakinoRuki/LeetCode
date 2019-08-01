// 一个pig测一次就是2^x桶。
// 两个pig测两次就是3*3数组，根据第几只pig第几次来划分维度。
// 因此n只pig就是n维，每一维宽度都是minsToTest / minsToDie + 1。
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int d = minutesToTest / minutesToDie + 1;
        int res = (int)ceil((log(buckets) / log(d)));
        return res;
    }
};
