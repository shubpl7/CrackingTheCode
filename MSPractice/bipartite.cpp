// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(int src, int parent, vector<int> adj[], vector<int> &color, int curr_color) {
        color[src]=curr_color;
        for(auto x: adj[src]) {
            if(x==parent)
                continue;
            if(color[x]==-1) {
                if(!dfs(x,src,adj,color,(color[src]^1)))
                    return false;
            }
            else if(color[x]==color[src])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> vis(V,false);
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++) {
	        if(color[i]==-1) {
	            if(!dfs(i,-1, adj,color,1))
	                return false;
	        }
	        
	    }
	    return true;
	}

};

// { Driver Code Starts.
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends