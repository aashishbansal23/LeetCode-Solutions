class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arrTemp = arr;
        sort(arrTemp.begin(), arrTemp.end());
        unordered_map<int, int> rankMap;
        vector<int> ans;
        int rank = 1;
        for(int i=0; i<arrTemp.size(); i++){
            if(rankMap.count(arrTemp[i]) == 0){
                rankMap[arrTemp[i]] = rank;
                rank++;
            }
        }
        for(auto a:arr){
            ans.push_back(rankMap[a]);
        }
        return ans;
    }
};