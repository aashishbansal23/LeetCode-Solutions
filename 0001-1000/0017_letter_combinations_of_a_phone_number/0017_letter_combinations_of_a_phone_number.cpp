class Solution {
    void helper(string digits, int index, vector<string>& ans, string output, string mapping[]){
        if(index >= digits.length()){
            if(output.length() == 0){
                return ;
            }
            ans.push_back(output);
            return ;
        }
        
        int num = digits[index] - '0';
        for(int i=0; i<mapping[num].length(); i++){
            output.push_back(mapping[num][i]);
            helper(digits, index+1, ans, output, mapping);
            output.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        string output = "";
        vector<string> ans;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, index, ans, output, mapping);
        return ans;
    }
};