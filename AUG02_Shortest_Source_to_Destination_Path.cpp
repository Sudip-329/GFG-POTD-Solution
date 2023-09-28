//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int i, int j, int N,int M ){
        if(i>=0 && i<N && j>=0 && j<M ) return true;
        return false;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<bool>> vis(N,vector<bool>(M,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        int steps=0;
        
        
         
        int dx[]={-1,0,+1,0};
        int dy[]={0,1,0,-1};
                
        
        while(!q.empty()){
            int size = q.size();
           while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if (i == X && j == Y) {
                    return steps;
                }
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if (isValid(ni, nj, N, M) && A[ni][nj] == 1 && !vis[ni][nj]) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
        }
        steps++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends