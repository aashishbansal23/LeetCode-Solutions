class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st;
        for(auto ele:arr){
            if(st.count(2*ele) > 0){
                return true;
            }else if((ele&1)==0 && st.count(ele/2)>0){
                return true;
            }else{
                st.insert(ele);
            }
        }
        return false;
    }
};