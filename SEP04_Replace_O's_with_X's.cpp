//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool isSafe(int i,int j,vector<vector<char>>& mat, vector<vector<bool>>&vis) {
        return (i >= 0 && j >= 0 and i<mat.size() and j < mat[0].size() and !vis[i][j] and mat[i][j] == 'O');
    }
    void dfs(int i,int j,vector<vector<char>>& mat, vector<vector<bool>>&vis){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            if(isSafe(i+dx[k],j+dy[k],mat,vis)) {
                dfs(i+dx[k],j+dy[k],mat,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        //doing dfs for zeros in first row
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i] == 'O'){
                dfs(0,i,mat,vis);
            }
        }
        
        //doing dfs for zeros in last row 
        
        for(int i=0;i<m;i++){
            if(!vis[n-1][i] &&mat[n-1][i] == 'O') {
                dfs(n-1,i,mat,vis);
            }
        }
        
        //doing dfs for in first column 
        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i,0,mat,vis);
            }
        }
        
       
        //doing dfs for in last column 
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i,m-1,mat,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' and !vis[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends