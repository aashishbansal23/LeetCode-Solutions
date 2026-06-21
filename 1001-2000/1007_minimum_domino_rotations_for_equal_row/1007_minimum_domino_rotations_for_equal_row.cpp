class Solution {
    int helper1(vector<int>& tops, vector<int>& bottoms, int num){
        int size = tops.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            if(tops[i] == num){
                continue;
            }else if(bottoms[i] == num){
                ans++;
            }else{
                return -1;
            }
        }
        return ans;
    }
    
    int helper2(vector<int>& tops, vector<int>& bottoms, int num){
        int size = tops.size();
        int ans = 0;
        for(int i=0; i<size; i++){
            if(bottoms[i] == num){
                continue;
            }else if(tops[i] == num){
                ans++;
            }else{
                return -1;
            }
        }
        return ans;
    }
    
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        if(tops.size() == 0){
            return 0;
        }
        
        int temp1 = helper1(tops, bottoms, tops[0]);
        int temp2 = helper2(tops, bottoms, tops[0]);
        int ans1 = -1;
        if(temp1!=-1 && temp2!=-1){
            ans1 = min(temp1, temp2);
        }else if(temp1 == -1){
            ans1 = temp2;
        }else if(temp2 == -1){
            ans1 = temp1;
        }
        int temp3 = helper1(tops, bottoms, bottoms[0]);
        int temp4 = helper2(tops, bottoms, bottoms[0]);
        int ans2 = -1;
        if(temp3!=-1 && temp4!=-1){
            ans2 = min(temp3, temp4);
        }else if(temp3 == -1){
            ans2 = temp4;
        }else if(temp4 == -1){
            ans2 = temp3;
        }
        if(ans1!=-1 && ans2!=-1){
            return min(ans1, ans2);
        }else if(ans1 == -1){
            return ans2;
        }else if(ans2 == -1){
            return ans1;
        }else{
            return -1;
        }
    }
};