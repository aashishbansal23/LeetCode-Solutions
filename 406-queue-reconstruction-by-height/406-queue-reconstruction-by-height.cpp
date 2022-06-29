class Solution {
    bool static compator(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1]<v2[1];
        }else{
            return v1[0]>v2[0];
        }
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compator);
        vector<vector<int>> ans;
        for(auto p:people){
            ans.insert(ans.begin()+p[1], p);
        }
        return ans;
    }
};