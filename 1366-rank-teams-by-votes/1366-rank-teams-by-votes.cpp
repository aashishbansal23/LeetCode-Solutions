class Solution {
    bool static compator(vector<int> v1, vector<int> v2){
        int teams = v1.size()-1;
        for(int i=0; i<teams; i++){
            if(v1[i] > v2[i]){
                return true;
            }else if(v1[i] < v2[i]){
                return false;
            }
        }
        return v1[teams]<v2[teams];
    }
    
public:
    string rankTeams(vector<string>& votes) {
        int voters = votes.size();
        if(voters == 1){
            return votes[0];
        }
        int teams = votes[0].length();
        vector<vector<int>> count(26, vector<int>(teams+1, 0));
        for(int i=0; i<voters; i++){
            for(int j=0; j<teams; j++){
                count[votes[i][j]-'A'][j]++;
            }
        }
        for(int i=0; i<26; i++){
            count[i][teams] = i;
        }
        sort(count.begin(), count.end(), compator);
        string ans = "";
        for(int i=0; i<teams; i++){
            ans.push_back(count[i][teams]+'A');
        }
        return ans;
    }
};