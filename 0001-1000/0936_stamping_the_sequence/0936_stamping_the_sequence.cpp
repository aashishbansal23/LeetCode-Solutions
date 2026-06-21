class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int total = 0;
        int turned = -1;
        while(turned){
            turned = 0;
            for(int k=stamp.size(); k>0; k--){
                for(int i=0; i<=stamp.size()-k; i++){
                    string temp = string(i,'*')+stamp.substr(i,k)+string(stamp.size()-k-i,'*');
                    auto position = target.find(temp);
                    while(position != string::npos){
                        ans.push_back(position);
                        turned += k;
                        fill(begin(target)+position, begin(target)+position+stamp.size(), '*');
                        position = target.find(temp);
                    }
                }
            }
            total += turned;
        }
        if(total == target.size()){
            reverse(ans.begin(), ans.end());
            return ans;
        }else{
            return {};
        }
        
        
        
        
        
        // Gives TLE
        // vector<int> ans;
        // int i = 0;
        // bool temp = false;
        // for(i=0; i<10*target.length(); i++){
        //     if(temp){
        //         break;
        //     }
        //     for(int j=0; j<=target.length()-stamp.length(); j++){
        //         bool flag = true;
        //         for(int k=0; k<stamp.length(); k++){
        //             if(stamp[k]==target[j+k] || target[j+k]=='*'){
        //                 continue;
        //             }else{
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if(flag){
        //             int count = 0;
        //             for(int k=0; k<stamp.length(); k++){
        //                 if(target[j+k] == '*'){
        //                     count++;
        //                 }
        //                 target[j+k] = '*';
        //             }
        //             if(count == stamp.length()){
        //                 continue;
        //             }
        //             ans.push_back(j);
        //             temp = true;
        //             for(int k=0; k<target.length(); k++){
        //                 if(target[k] != '*'){
        //                     temp = false;
        //                     break;
        //                 }
        //             }
        //             break;
        //         }
        //     }
        // }
        // if(i < 10*target.length()){
        //     reverse(ans.begin(), ans.end());
        //     return ans;
        // }else{
        //     return {};
        // }
    }
};