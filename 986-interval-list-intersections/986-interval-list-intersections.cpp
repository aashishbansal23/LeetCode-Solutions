class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int size1 = firstList.size();
        int size2 = secondList.size();
        vector<vector<int>> ans;
        if(size1==0 || size2==0){
            return ans;
        }
        int i=0, j=0;
        while(i<size1 && j<size2){
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];
            int s2 = secondList[j][0];
            int e2 = secondList[j][1];
            int first;
            int second;
            if(e1>=s2 && e2>=s1){
                first = max(s1, s2);
                second = min(e1, e2);
                if(second == e1){
                    i++;
                }else{
                    j++;
                }
                if(ans.empty()){
                    ans.push_back({first, second});
                }else{
                    if(ans[ans.size()-1][1] >= first){
                        ans[ans.size()-1][1] = max(ans[ans.size()-1][1], second);
                    }else{
                        ans.push_back({first, second});
                    }
                }
            }else if(e2 < s1){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};