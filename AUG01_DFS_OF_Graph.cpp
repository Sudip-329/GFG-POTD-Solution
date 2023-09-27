//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void dfs(int node, vector<int>adj[], vector<int>&ans, vector<int>&vis){
        vis[node]= 1;  //1st node(0) will always be visited.
        ans.push_back(node);  // PUsh the visited node to ans
        for(auto it: adj[node]){  // now check (0 or other) nodes adjacent nodes visited or not
            if(vis[it]==-1){  // if vis = -1 means not visited as -1 is the initial value
                dfs(it,adj,ans,vis);  //perform the recursive call!!!
            }
        }
    }
    vector<int>dfsOfGraph(int V, vector<int>adj[]){
        vector<int> ans;
        vector<int>vis(V,-1); //Making initially -1
        dfs(0,adj,ans,vis);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends