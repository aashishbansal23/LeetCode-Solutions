// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class data{
    public:
    int val;
    int r;
    int c;
    data(int val, int r, int c){
        this->val = val;
        this->r = r;
        this->c = c;
    }
};

class compator{
    public:
    bool operator()(data d1, data d2){
        return d1.val>d2.val;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<data, vector<data>, compator> pq;
          int minn = INT_MAX;
          int maxx = INT_MIN;
          for(int i=0; i<k; i++){
              data d(KSortedArray[i][0], i, 0);
              pq.push(d);
              maxx = max(maxx, KSortedArray[i][0]);
              minn = min(minn, KSortedArray[i][0]);
          }
          int currMin = minn;
          int currMax = maxx;
          while(!pq.empty()){
              data d = pq.top();
              pq.pop();
              currMin = d.val;
              if(maxx-minn > currMax-currMin){
                  maxx = currMax;
                  minn = currMin;
              }
              if(d.c < n-1){
                  currMax = max(currMax, KSortedArray[d.r][d.c+1]);
                  d.val = KSortedArray[d.r][d.c+1];
                  d.c++;
                  pq.push(d);
              }else{
                  break;
              }
          }
          return {minn, maxx};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends