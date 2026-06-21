class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hsize = horizontalCuts.size();
        int vsize = verticalCuts.size();
        int height = max(horizontalCuts[0], h-horizontalCuts[hsize-1]);
        int width = max(verticalCuts[0], w-verticalCuts[vsize-1]);
        for(int i=1; i<hsize; i++){
            height = max(height, horizontalCuts[i]-horizontalCuts[i-1]);
            height = (height%1000000007);
        }
        for(int i=1; i<vsize; i++){
            width = max(width, verticalCuts[i]-verticalCuts[i-1]);
            width = (width%1000000007);
        }
        return (((long long)height*(long long)width)%1000000007);
    }
};