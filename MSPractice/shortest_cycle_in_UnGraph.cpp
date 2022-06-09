// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, int p, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
    {
        vis[src] = true;
        path[src] = true;
        for (auto x : adj[src])
        {
            if (!vis[x])
            {
                if (dfs(x, src, adj, vis, path))
                    return true;
            }
            else if (path[x])
            {
                return true;
            }
        }
        path[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis, path))
                    return true;
            }
        }
        return false;
    }

    int bfs(int src, int V, vector<int> adj[], int & ans) {
        queue<int> q;
        vector<int> dis(V, INT_MAX);
        dis[src]=0;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto x:adj[u]) {
                if(dis[x]==INT_MAX) {
                    dis[x]=dis[u]+1;
                    q.push(x);
                }
                else if(dis[x]>=dis[u]){
                    ans=min(ans, dis[u]+dis[x]+1);
                    cout<<"Cycle found between "<<u<<" and "<<x<<" of size: "<<dis[u]+dis[x]+1<<endl;
                }
            }
        }
        for(auto x:dis)
            cout<<x<<" ";
        cout<<endl;
        return ans;
    }

    void shortestcycle(int V, vector<int> adj[]) {
        //
        
        queue<int> q;
        int ans = INT_MAX;
        for(int i=0;i<V;i++) {
            ans = min(ans, bfs(i, V,adj,ans));
        }
        cout<<"Shortest Cycle len. is: "<<ans;
    }

};

// { Driver Code Starts.

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        obj.shortestcycle(V,adj);
        //cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends