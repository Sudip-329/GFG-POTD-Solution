//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        unordered_map<int,int>ans;   // not in o(1) space
        for(int i=0; i<N; i++)
        {
            ans[arr[i]]++;
        }
        for(auto i : ans)
        {
            if(i.second==1)
            {
                return i.first;
            }
        }*/
        
       /*int ans=0;    //works when said twice not thrice
	   for(auto x: arr)
	   ans^=x;
	   return ans;*/
	   
class Solution {
  public:
    int singleElement(int nums[] ,int N) {
       int res = 0;
        for (int i = 0; i < 32; i++) {   //32 is constant so not n square
            int ans = 0;
            for (int j = 0; j < N; j++) {
                if ((nums[j] & (1 << i)) != 0)
                    ans++;
            }
            if (ans % 3 == 1)
                res += (1 << i);
        }
        return res;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends