//finding cycle in undirected graph
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, int parent, vector<int> adj[], vector<bool> &vis){
       vis[src]=true;
       //adj of src
       for(auto it:adj[src]){
           if(!vis[it]){
               bool cycle_mila = dfs(it, src, adj, vis);
               if(cycle_mila)
                    return true;
           }
           else if(it!=parent){
               return true;
           }
       }
       return false;
   }
   bool bfs(int src, int parent, vector<int> adj[], vector<bool> &vis) {
       queue<pair<int,int>> q;
       q.push({src,-1});
       vis[src]=true;
       while(!q.empty()) {
           auto u = q.front();
           int node = u.first;
           int parent = u.second;
           q.pop();
           for(auto v:adj[node]) {
               if(!vis[v]) {
                   vis[v]=1;
                   q.push({v,node});
               }
               else if(v!=parent)
                    return true;
           }
       }
       return false;
   }
   bool isCycle(int V, vector<int> adj[]) {
       // Code here
       vector<bool>vis(V,false);
       for(int i =0;i<V;i++){
           if(!vis[i]){
               bool f = bfs(i,-1,adj,vis);
               if(f){
                   return true;
               }
           }
       }
       return false;
   }
};

// { Driver Code Starts.
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends