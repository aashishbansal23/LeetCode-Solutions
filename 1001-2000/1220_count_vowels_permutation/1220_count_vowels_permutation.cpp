class Solution {
    int mod = 1e9+7;
    
    int countVowelPermutationRecursion(int& n, string& str){
        if(str.length() == n){
            return 1;
        }
        if(str.length() == 0){
            str.push_back('a');
            int a = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('e');
            int e = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('i');
            int i = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('o');
            int o = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('u');
            int u = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return (a%mod + e%mod + i%mod + o%mod + u%mod)%mod;
        }
        if(str.back() == 'a'){
            str.push_back('e');
            int e = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return e%mod;
        }else if(str.back() == 'e'){
            str.push_back('a');
            int a = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('i');
            int i = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return (a%mod + i%mod)%mod;
        }else if(str.back() == 'i'){
            str.push_back('a');
            int a = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('e');
            int e = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('o');
            int o = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('u');
            int u = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return (a%mod + e%mod + o%mod + u%mod)%mod;
        }else if(str.back() == 'o'){
            str.push_back('i');
            int i = countVowelPermutationRecursion(n, str);
            str.pop_back();
            str.push_back('u');
            int u = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return (i%mod + u%mod)%mod;
        }else if(str.back() == 'u'){
            str.push_back('a');
            int a = countVowelPermutationRecursion(n, str);
            str.pop_back();
            return a%mod;
        }else{
            return 0;
        }
    }
    
    int countVowelPermutationDP(int n){
        vector<vector<int>> relation = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}}; // a, e, i, o, u
        vector<long long> vowels(5, 1), temp;
        while(--n){
            temp = vowels;
            for(int i=0; i<5; i++){
                vowels[i] = 0;
                for(auto r:relation[i]){
                    vowels[i] += temp[r];
                    vowels[i] %= mod;
                }
            }
        }
        long long ans = 0;
        for(auto i:vowels){
            ans += i;
            ans %= mod;
        }
        return ans;
    }
    
public:
    int countVowelPermutation(int n) {
        // string str = "";
        // return countVowelPermutationRecursion(n, str);
        
        return countVowelPermutationDP(n);
    }
};