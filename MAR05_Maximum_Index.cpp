//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> right(n);
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)right[i]=max(a[i],right[i+1]);
        int i=0,j=0,ans=INT_MIN;
        while(i<n and j<n){
            if(a[i]<=right[j]){
                ans=max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};



/*class Solution{    //TLE as n^2
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int ans = 0,maxi=0;
        // Your code here
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(i<j)
                {
                    if(a[i]<a[j])
                    {
                        ans = j-i;
                    }
                }
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
};*/

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends