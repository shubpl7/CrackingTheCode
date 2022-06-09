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
};

// { Driver Code Starts.

int main()
{

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
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends