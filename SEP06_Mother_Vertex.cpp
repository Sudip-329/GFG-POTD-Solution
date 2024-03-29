//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(int i,vector<int>& vis, vector<int> adj[]){
        vis[i]=1;
        for(auto it : adj[i])
            if(!vis[it])
                dfs(it,vis,adj);
        return;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int ans=0; //minimum mother vertex
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            ans=i;// assume it may be the ans
	            dfs(i,vis,adj);
	        }
	    }
	    vis = vector<int>(V,0);
	    dfs(ans,vis,adj);
	    for(int x:vis)
	        if(!x) return -1;
	       
	   return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends