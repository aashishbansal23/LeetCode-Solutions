class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(), deadends.end());
        string start = "0000";
        if(visited.count(start)){
            return -1;
        }
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                start = q.front();
                q.pop();
                if(start == target){
                    return ans;
                }
                for(int i=0; i<start.length(); i++){
                    string temp = start;
                    char ch = start[i];
                    int chr = (ch+1-'0')%10;
                    ch = chr+'0';
                    temp[i] = ch;
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                    ch = start[i];
                    chr = ch-'0';
                    if(chr == 0){
                        chr = 9;
                    }else{
                        chr--;
                    }
                    ch = chr+'0';
                    temp[i] = ch;
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
                size--;
            }
            ans++;
        }
        return -1;
    }
};