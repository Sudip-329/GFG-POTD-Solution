//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isPossible(int sum, int k, int arr[], int n){
        int curSum=0;
        
        for(int i=0;i<n;i++){
            if(curSum+arr[i]>sum){
                k-=1;
                curSum=arr[i];
            } else{
                curSum+=arr[i];
            }
        }
        
        return k>0;
    }
    
    int splitArray(int arr[] ,int n, int k) {
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        
        int ans=high;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isPossible(mid,k,arr,n)){
                ans=mid;
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends