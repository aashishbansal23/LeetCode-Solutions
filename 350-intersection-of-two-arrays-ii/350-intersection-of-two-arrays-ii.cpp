class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ourmap;
        for(int i=0; i<nums1.size(); i++){
            if(ourmap.count(nums1[i]) > 0){
                ourmap[nums1[i]]++;
            }else{
                ourmap[nums1[i]] = 1;
            }
        }
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            if(ourmap.count(nums2[i])>0 && ourmap[nums2[i]]>0){
                ans.push_back(nums2[i]);
                ourmap[nums2[i]]--;
            }
        }
        return ans;
    }
};