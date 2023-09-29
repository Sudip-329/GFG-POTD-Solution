//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int searchpart1(int arr[],int low, int high,int x)
    {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == x) {
                ans = mid;
                high = mid-1;
            } else if(arr[mid] < x) {
                low =  mid + 1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
    int searchpart2(int arr[],int low, int high,int x)
    {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == x) {
                ans = mid;
                low = mid+1;
            } else if(arr[mid] < x) {
                low =  mid + 1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x)
    {
        vector<int>ans;
        int first = searchpart1(arr,0,n-1,x);
        int last = searchpart2(arr,0,n-1,x);
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
    }

    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends