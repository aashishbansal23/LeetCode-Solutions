class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> possible(bank.begin(), bank.end());
        if(!possible.count(end)){
            return -1;
        }
        set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                start = q.front();
                q.pop();
                if(start == end){
                    return ans;
                }
                for(int i=0; i<start.length(); i++){
                    string temp = start;
                    temp[i] = 'A';
                    if(possible.count(temp) && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                    temp[i] = 'C';
                    if(possible.count(temp) && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                    temp[i] = 'G';
                    if(possible.count(temp) && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                    temp[i] = 'T';
                    if(possible.count(temp) && !visited.count(temp)){
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