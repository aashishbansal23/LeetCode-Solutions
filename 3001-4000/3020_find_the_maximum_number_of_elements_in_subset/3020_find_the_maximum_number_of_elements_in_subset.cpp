class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for(int num:nums){
            frequency[num]++;
        }
        int ans = max(1, (frequency[1]&1) == 0 ? frequency[1]-1 : frequency[1]);
        frequency.erase(1);
        for(int num:nums){
            if(num != 1 && frequency[num] > 1){
                int tempCount = 0;
                long long tempNum = num;
                while(tempNum <= INT_MAX && frequency[tempNum] > 0){
                    if(frequency[tempNum] == 1){
                        tempCount++;
                        break;
                    }
                    tempCount++;
                    if(tempNum > LLONG_MAX/tempNum){
                        break;
                    }
                    tempNum *= tempNum;
                }
                ans = max(ans, 2*tempCount-1);
            }
        }
        return ans;
    }
};