class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxx = INT_MIN;
        while(i < j){
            maxx = max(maxx, min(height[j], height[i])*(j-i));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxx;
    }
};