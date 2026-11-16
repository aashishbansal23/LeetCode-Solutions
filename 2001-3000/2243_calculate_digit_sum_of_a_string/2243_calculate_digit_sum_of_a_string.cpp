class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            int i = 0;
            string temp = "";
            while(i < s.length()){
                int j = 0;
                int num = 0;
                while(j<k && i<s.length()){
                    num += (s[i]-'0');
                    j++;
                    i++;
                }
                temp.append(to_string(num));
            }
            s = temp;
        }
        return s;
    }
};