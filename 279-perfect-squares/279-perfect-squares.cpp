class Solution {
public:
    int numSquares(int n) {
        set<int> s;
        queue<int> q;
        q.push(n);
        s.insert(n);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                n = q.front();
                q.pop();
                int num = sqrt(n);
                if(num*num == n){
                    return count;
                }
                for(int i=1; i<n; i++){
                    if(n-i*i>=0 && s.count(n-i*i)==0){
                        q.push(n-i*i);
                        s.insert(n-i*i);
                    }else if(n-i*i < 0){
                        break;
                    }
                }
            }
            count++;
        }
        return count;
    }
};