class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Without Using Extra Space
        int len = pushed.size();
        int i=0, j=0, k=0;
        while(i<len && j<len){
            if(pushed[i] == popped[j]){
                i++;
                j++;
            }else if(k>0 && pushed[k-1]==popped[j]){
                k--;
                j++;
            }else{
                pushed[k++] = pushed[i++];
            }
        }
        while(k>0 && j<len){
            if(pushed[k-1] == popped[j]){
                k--;
                j++;
            }else{
                return false;
            }
        }
        if(j == len){
            return true;
        }
        return false;
        
        
        
        
        /*
        // Using Space
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
        */
    }
};