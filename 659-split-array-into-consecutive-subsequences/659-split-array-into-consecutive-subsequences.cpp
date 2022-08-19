class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for(auto num:nums){
            frequency[num]++;
        }
        unordered_map<int, int> last;
        for(auto num:nums){
            if(frequency[num] == 0){
                continue;
            }
            frequency[num]--;
            if(last[num-1] > 0){
                last[num-1]--;
                last[num]++;
            }else if(frequency[num+1]>0 && frequency[num+2]>0){
                frequency[num+1]--;
                frequency[num+2]--;
                last[num+2]++;
            }else{
                return false;
            }
        }
        return true;
    }
};