class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i=1; i<=9; i++){
            q.push(i);
        }
        int digits = 1;
        while(digits < n){
            int size = q.size();
            while(size-- > 0){
                int num = q.front();
                q.pop();
                if((num%10)+k <= 9){
                    int temp = ((num*10) + (num%10)+k);
                    q.push(temp);
                }
                for(int j=0; j<=9; j++){
                    if(abs((num%10)-j) == k){
                        int temp = ((num*10)+j);
                        q.push(temp);
                        break;
                    }
                }
                // if(abs((num%10)-k) <= k){
                //     int temp = ((num*10) + abs((num%10)-k));
                //     q.push(temp);
                // }
            }
            digits++;
        }
        set<int> s;
        while(!q.empty()){
            s.insert(q.front());
            q.pop();
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};