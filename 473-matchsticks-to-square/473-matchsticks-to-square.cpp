class Solution {
    // bool makeSquare(int sum1, int sum2, int sum3, int sum4, vector<int>& matchsticks, int i, int& size){
    //     if(i == size){
    //         if(sum1==sum2 && sum2==sum3 && sum3==sum4){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }
    //     if(makeSquare(sum1+matchsticks[i], sum2, sum3, sum4, matchsticks, i+1, size)){
    //         return true;
    //     }else if(makeSquare(sum1, sum2+matchsticks[i], sum3, sum4, matchsticks, i+1, size)){
    //         return true;
    //     }else if(makeSquare(sum1, sum2, sum3+matchsticks[i], sum4, matchsticks, i+1, size)){
    //         return true;
    //     }else if(makeSquare(sum1, sum2, sum3, sum4+matchsticks[i], matchsticks, i+1, size)){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
    
    bool makeSquare(int index, vector<int>& matchsticks, vector<int>& sides, int& side){
        if(index == matchsticks.size()){
            if(sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]){
                return true;
            }else{
                return false;
            }
        }
        for(int i=0; i<4; i++){
            if(sides[i]+matchsticks[index] > side){
                continue;
            }
            int j = i-1;
            while(j >= 0){
                if(sides[j] == sides[i]){
                    break;
                }
                j--;
            }
            if(j != -1){
                continue;
            }
            sides[i] += matchsticks[index];
            if(makeSquare(index+1, matchsticks, sides, side)){
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4){
            return false;
        }
        int sum = 0;
        for(auto i:matchsticks){
            sum += i;
        }
        if(sum%4 != 0){
            return false;
        }
        int side = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        if(matchsticks[0] > side){
            return false;
        }
        vector<int> sides(4, 0);
        return makeSquare(0, matchsticks, sides, side);
        
        
        
        
        
        // First Try Gives TLE
        // int size = matchsticks.size();
        // if(size < 4){
        //     return false;
        // }
        // return makeSquare(0, 0, 0, 0, matchsticks, 0, size);
    }
};