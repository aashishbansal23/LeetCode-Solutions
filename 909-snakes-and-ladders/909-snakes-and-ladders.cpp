class Solution {
    pair<int,int> getCoordinates(int front, int n){
        int r = n-(front-1)/n-1;
        int c = (front-1)%n;
        if((r%2)==(n%2)){
            c = n-c-1;
        }
        return {r, c};
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n*n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int front = q.front();
                q.pop();
                if(front == n*n){
                    return ans; 
                }
                for(int j=1; j<=6; j++){
                    int temp = front+j;
                    if(temp<=n*n && !visited[temp]){
                        pair<int, int> p = getCoordinates(temp, n);
                        int r = p.first;
                        int c = p.second;
                        if(board[r][c] == -1){
                            q.push(temp);
                            visited[temp] = true;
                        }else if(!visited[board[r][c]]){
                            q.push(board[r][c]);
                            visited[temp] = true;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};