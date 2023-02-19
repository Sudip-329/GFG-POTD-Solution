//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i=0, j=0, cta=0, ctb =0, ans =0;
        while(j<n)
        {
            if(arr[j] == 'A')
            {
                cta++;
            }
            else
            {
                if(ctb<m)
                {
                    ctb++;
                }
                else{
                    while(i<j && arr[i] != 'O')
                    {
                        i++;
                        cta--;
                    }
                    i++;
                }
            }
            ans = max(ans, cta+ctb);
            j++;
        }
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends