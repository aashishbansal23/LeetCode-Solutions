class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest/minutesToDie;
        return ceil(log(buckets)/log(tests+1));
    }
};