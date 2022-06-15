class data1{
    public:
    int val;
    int r;
    int c;
    data1(int val, int r, int c){
        this->val = val;
        this->r = r;
        this->c = c;
    }
};

class compator{
    public:
    bool operator()(data1 d1, data1 d2){
        return d1.val>d2.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<data1, vector<data1>, compator> pq;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i=0; i<k; i++){
            data1 d(nums[i][0], i, 0);
            pq.push(d);
            minn = min(minn, nums[i][0]);
            maxx = max(maxx, nums[i][0]);
        }
        int currMin = minn;
        int currMax = maxx;
        while(!pq.empty()){
            data1 d = pq.top();
            pq.pop();
            currMin = d.val;
            if(currMax-currMin < maxx-minn){
                maxx = currMax;
                minn = currMin;
            }
            if(d.c < nums[d.r].size()-1){
                d.c++;
                d.val = nums[d.r][d.c];
                pq.push(d);
                currMax = max(currMax, nums[d.r][d.c]);
            }else{
                break;
            }
        }
        return {minn, maxx};
    }
};