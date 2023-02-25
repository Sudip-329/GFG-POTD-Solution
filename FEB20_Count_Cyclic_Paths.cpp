//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

int arr[1000010][4];

class Solution{   
public:
    int countPaths(int N){
        const int mod = 1e9 + 7;
        
        for(int i = 0; i < 4; i++) arr[0][i] = 0;
        arr[0][0] = 1;
        
        for(int i = 1; i < N + 1; i++){
            for(int j = 0; j < 4; j++){
                int x = (j + 1) % 4;
                int y = (j - 1 + 4) % 4;
                int z = (j + 6) % 4;
                
                arr[i][j] = (arr[i - 1][x] + arr[i - 1][y]) % mod;
                arr[i][j] = (arr[i][j] + arr[i - 1][z]) % mod;
            }
        }
        return arr[N][0];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}