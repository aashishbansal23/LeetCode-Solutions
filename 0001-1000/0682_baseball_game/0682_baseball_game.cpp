class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        int len = ops.size();
        for(int i=0; i<len; i++){
            if(ops[i] == "+"){
                int t = scores.top();
                scores.pop();
                t += scores.top();
                scores.push(t-scores.top());
                scores.push(t);
            }else if(ops[i] == "C"){
                scores.pop();
            }else if(ops[i] == "D"){
                scores.push(2*scores.top());
            }else{
                scores.push(stoi(ops[i]));
            }
        }
        int ans = 0;
        while(!scores.empty()){
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
};