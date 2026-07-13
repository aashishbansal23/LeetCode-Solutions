class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(low > high){
            return {};
        }
        
        vector<int> ans;
        string num = "123456789";
        int low_l = to_string(low).size();
        int high_l = to_string(high).size();
        
        for(int i=low_l; i<=high_l; i++){
            for(int j=0; j<10-i; j++){
                int temp = stoi(num.substr(j,i));
                if(temp>=low && temp<=high){
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};