class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        int minn = min(cost1, cost2);
        int maxx = max(cost1, cost2);
        for(long long i=0; i*minn<=total; i++){
            int cost = total-i*minn;
            ans += (cost/maxx)+1;
            // for(long long j=0; j*cost2+i*cost1<=total; j++){
            //     ans++;
            // }
        }
        return ans;
    }
};