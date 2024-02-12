//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans = 1,temp=2,mod=1e9+7;
        int i = 2;
        while(i<=n){
            int j = i;
            long long temp2 = 1;
            while(j--){
                temp2*=temp;
                temp2%=mod;
                temp++;
            }
            ans+=temp2;
            //ans%=mod;
            i++;
        }
        return ans % mod;
    }
};*/


//User function Template for C++

class Solution{
public:
    long long sequence(int n){  //my
        // code herejjhfg
        long long a = 1e9+7;
        long long k = 1; 
        long long ans2 = 0;
        for(int i=1; i<=n; i++)
        {
            long long ans = 1;
            for(int j=1; j<=i; j++)
            {
                ans = ans* k;
                ans%=a;
                k++;
                //cout<<k;
            }
            ans2+=ans;
        }
        return ans2%a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends