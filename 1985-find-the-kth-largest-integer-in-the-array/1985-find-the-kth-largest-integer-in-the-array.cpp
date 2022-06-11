class Solution {
    static bool compator(string s1, string s2){
        if(s1.length() > s2.length()){
            return true;
        }else if(s1.length() == s2.length()){
            return s1 > s2;
        }else{
            return false;
        }
    }
    
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int size = nums.size();
        if(k > size){
            return "";
        }
        sort(nums.begin(), nums.end(), compator);
        priority_queue<string, vector<string>, greater<string>> pq;
        for(int i=0; i<k; i++){
            if(pq.empty()){
                pq.push(nums[i]);
                continue;
            }
            string temp = pq.top();
            if(temp.length()==nums[i].length()){
                pq.push(nums[i]);
            }else{
                while(!pq.empty()){
                    pq.pop();
                }
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};