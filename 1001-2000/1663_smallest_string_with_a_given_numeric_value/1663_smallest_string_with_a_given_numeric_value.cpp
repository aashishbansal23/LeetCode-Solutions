class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i=0; i<n; i++){
            ans += 'a';
        }
        k -= n;
        for(int i=n-1; i>=0; i--){
            if(k == 0){
                break;
            }else if(k < 25){
                ans[i] = (char)('a'+k);
                k = 0;
            }else{
                ans[i] = (char)('a'+25);
                k -= 25;
            }
        }
        return ans;
        
        
        
        
        // string ans = "";
        // for(int i=n; i>0; i--){
        //     for(int j=26; j>0; j--){
        //         if(k-j >= i-1){
        //             char temp = 'a'+j-1;
        //             ans = temp+ans;
        //             k -= j;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        
        
        // string ans = "";
        // for(int i=1; i<=n; i++){
        //     if(k<=26 && i==n){
        //         char temp = 'a'+(k-1);
        //         ans = ans+temp;
        //         break;
        //     }
        //     for(int j=26; j>0; j--){
        //         if((k-(n-i)*j) <= 0){
        //             char temp = 'a'+(26-j);
        //             ans = ans+(temp);
        //             k = k-(26-j+1);
        //             break;
        //         }else{
        //             char temp ='a'+(k-(n-i)*26-1);
        //             ans = ans+(temp);
        //             k = (n-i)*26;
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};