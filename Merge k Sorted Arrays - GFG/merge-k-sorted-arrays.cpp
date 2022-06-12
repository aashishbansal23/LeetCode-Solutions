// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class data{
    public:
    int val;
    int r;
    int c;
};

class compator{
    public:
    bool operator()(data a, data b){
        return a.val>b.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<data, vector<data>, compator> pq;
        for(int i=0; i<K; i++){
            data temp;
            temp.val = arr[i][0];
            temp.r = i;
            temp.c = 0;
            pq.push(temp);
        }
        while(!pq.empty()){
            data front = pq.top();
            pq.pop();
            ans.push_back(front.val);
            if(front.c != K-1){
                front.c++;
                front.val = arr[front.r][front.c];
                pq.push(front);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends