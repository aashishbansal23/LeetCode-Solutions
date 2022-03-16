class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len1 = pushed.size();
        int len2 = popped.size();
        if(len2 == 0){
            return true;
        }else if(len1 == 0){
            return false;
        }
        
        stack<int> s;
        int i=0, j=0;
        while(i<len1 && j<len2){
            if(s.empty()){
                s.push(pushed[i]);
                i++;
            }else if(s.top() == popped[j]){
                s.pop();
                j++;
            }else{
                s.push(pushed[i]);
                i++;
            }
        }
        while(!s.empty() && j<len2){
            if(s.top() == popped[j]){
                s.pop();
                j++;
            }else{
                return false;
            }
        }
        if(j == len2){
            return true;
        }
        return false;
    }
};