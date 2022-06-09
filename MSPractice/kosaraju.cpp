//strongly connected components
//kosaraju algorithm

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void dfs(int src, vector<bool> &vis, vector<vector<int> > &graph, vector<int> &stk)
{
    cout<<src<<" "<<endl;
    vis[src] = true;
    for (auto x : graph[src])
    {
        if (!vis[x])
            dfs(x, vis, graph, stk);
    }
    stk.push_back(src);
}

void dfs2(int src, vector<bool> &vis1, vector<vector<int> > &revgraph)
{
    cout << src << " ";
    vis1[src] = true;
    for (auto x : revgraph[src])
    {
        if (!vis1[x])
            dfs2(x, vis1, revgraph);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int v, e;
    cin >> v >> e;
    vector<vector<int> > graph, revgraph;
    graph.resize(v);
    revgraph.resize(v);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        revgraph[b].push_back(a);
    }
    vector<int> stk;
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, graph, stk);
    }
    cout<<"DFS1 ends\n";
    char comp = 'A';
    reverse(stk.begin(),stk.end());
    vector<bool> vis1;
    vis1.resize(v,false);

    for (auto x:stk)
    {
        if (!vis1[x])
        {
            cout << "component " << comp++<< "---> ";
            dfs2(x, vis1, revgraph);
            cout << endl;
        }
        
    }

    return 0;
}