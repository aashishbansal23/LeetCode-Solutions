// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
    // bool isPossible(int arr[], int n, int k, int mid){
    //     int sum = 0;
    //     int count = 1;
    //     for(int i=0; i<n; i++){
    //         if(sum+arr[i] <= mid){
    //             sum += arr[i];
    //         }else{
    //             count++;
    //             if(count>k || arr[i]>mid){
    //                 return false;
    //             }
    //             sum = arr[i];
    //         }
    //     }
    //     return true;
    // }
    
    bool isPossible(int arr[], int mid, int n, int k){
        int count = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            if(sum+arr[i] > mid){
                count++;
                if(count>k || arr[i]>mid){
                    return false;
                }
                sum = arr[i];
            }else{
                sum += arr[i];
            }
        }
        return true;
    }
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int low = INT_MAX;
        long long high = 0;
        for(int i=0; i<n; i++){
            low = min(low, arr[i]);
            high += arr[i];
        }
        
        long long ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(isPossible(arr, mid, n, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(ans == -1){
            return low;
        }else{
            return ans;
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int s = INT_MAX;
        // long long e = 0;
        // for(int i=0; i<n; i++){
        //     s = min(s, arr[i]);
        //     e += arr[i];
        // }
        
        // long long ans = -1;
        // while(s <= e){
        //     int mid = s+(e-s)/2;
        //     if(isPossible(arr, n, k, mid)){
        //         e = mid-1;
        //         ans = mid;
        //     }else{
        //         s = mid+1;
        //     }
        // }
        // if(ans == -1){
        //     return s;
        // }else{
        //     return ans;
        // }
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends