class dataa{
    public:
    int index;
    string source;
    string target;
};

bool compator(dataa d1, dataa d2){
    return d1.index<d2.index;
}

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        dataa d[k];
        for(int i=0; i<k; i++){
            d[i].index = indices[i];
            d[i].source = sources[i];
            d[i].target = targets[i];
        }
        sort(d, d+k, compator);
        for(int i=0; i<k; i++){
            indices[i] = d[i].index;
            sources[i] = d[i].source;
            targets[i] = d[i].target;
        }
        string ans = "";
        for(int i=0; i<s.length(),i<indices[0]; i++){
            ans.push_back(s[i]);
        }
        for(int i=0; i<k; i++){
            if(s.substr(indices[i], sources[i].length()) == sources[i]){
                ans += targets[i];
                if(i != k-1){
                    int j = indices[i]+sources[i].length();
                    while(j<s.length() && j<indices[i+1]){
                        ans.push_back(s[j++]);
                    }
                }else{
                    int j = indices[i]+sources[i].length();
                    while(j < s.length()){
                        ans.push_back(s[j++]);
                    }
                }
            }else{
                if(i != k-1){
                    int j = indices[i];
                    while(j<s.length() && j<indices[i+1]){
                        ans.push_back(s[j++]);
                    }
                }else{
                    int j = indices[i];
                    while(j < s.length()){
                        ans.push_back(s[j++]);
                    }
                }
            }
        }
        return ans;
    }
};