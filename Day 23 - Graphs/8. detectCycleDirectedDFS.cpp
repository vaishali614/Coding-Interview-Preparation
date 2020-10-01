// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> adj[], int n, int i, vector<bool> &visited, vector<bool> &track, bool &ans){
    visited[i] = true;
    track[i] = true;
    for(int j: adj[i]){
        if(track[j])
            ans = true;
        if(!visited[j])
            dfs(adj,n,j,visited,track,ans);
    }
    track[i] = false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
    vector<bool> track(V,false);
    bool ans = false;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(adj, V, i, visited, track, ans);
            if(ans)
                return true;
        }
            
    }
    return false;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
} 