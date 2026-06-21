class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        while(i <= j){
            if(i == j){
                if(people[i] <= limit){
                    ans++;
                    i++;
                    j--;
                    continue;
                }
            }
            if(people[j] == limit){
                ans++;
                j--;
            }else if(people[i]+people[j] <= limit){
                ans++;
                i++;
                j--;
            }else if(people[i]+people[j] > limit){
                ans++;
                j--;
            }
        }
        return ans;
    }
};