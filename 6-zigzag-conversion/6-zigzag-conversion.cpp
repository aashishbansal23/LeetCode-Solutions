class Solution {
    void insertInAllRows(int& i, string& s, string v[], int& numRows){
        int j = 0;
        while(i<s.length() && j<numRows){
            v[j].push_back(s[i]);
            i++;
            j++;
        }
    }
    
    void insertTwoLess(int& i, string& s, string v[], int& numRows){
        int j = numRows-2;
        while(i<s.length() && j>0){
            v[j].push_back(s[i]);
            i++;
            j--;
        }
    }
    
public:
    string convert(string s, int numRows) {
        if(numRows<2 || s.length()<2){
            return s;
        }
        string v[numRows];
        int i = 0;
        while(i < s.length()){
            insertInAllRows(i, s, v, numRows);
            insertTwoLess(i, s, v, numRows);
        }
        string ans = "";
        for(auto st:v){
            ans += st;
        }
        return ans;
    }
};
// "PAYPA LIS HIRING"
// P   H
// A S I
// Y I R
// P L I G
// A   N

// P   R
// A I I
// Y H N
// P S G
// A I
// L