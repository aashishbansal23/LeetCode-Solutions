class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // for(int i=1e9; i>0; i--){
        //     cout << i << endl;
        // }
        string number = to_string(n);
        vector<int> freq(10, 0);
        for(auto num:number){
            freq[num-'0']++;
        }
        for(int i=0; i<31; i++){
            string temp = to_string((int)pow(2,i));
            vector<int> tempFreq(10, 0);
            for(auto num:temp){
                tempFreq[num-'0']++;
            }
            if(freq == tempFreq){
                return true;
            }
        }
        return false;
    }
};