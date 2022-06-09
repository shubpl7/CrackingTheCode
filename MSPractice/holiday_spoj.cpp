#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
vector<vector<PII>> adj;
int n, ans;
void addEdge(int u, int v, int wt)
{
    adj[u].PB({v, wt});
    adj[v].PB({u, wt});
}

int dfs(int src, int parent)
{
    int child = 1;
    for (auto x : adj[src])
    {
        if (x.first == parent)
            continue;
        int nx = dfs(x.first, src);
        child += nx;
        ans += max(nx, n - nx) * 2 * x.second;
    }
    return child;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        ans = 0;
        adj.resize(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b, wt;
            cin >> a >> b >> wt;
            addEdge(a, b, wt);
        }
        dfs(1, -1);
        cout << "Case #" << t << ": " << ans << endl;
        adj.clear();
    }
    return 0;
}