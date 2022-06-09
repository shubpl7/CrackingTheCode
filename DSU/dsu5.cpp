#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
bool comp(const pair<PII, int> a, const pair<PII, int> b)
{
       return a.se < b.se;
}
class mycomp
{
public:
       bool operator()(PII a, PII b)
       {
              return b.se < a.se;
       }
};
class graph
{
public:
       vector<pair<PII, int>> edges;
       VI parents;
       VI ranks;
       int V;
       graph(int vert)
       {
              this->V = vert;
              parents.resize(V + 1, -1);
              ranks.resize(V + 1, 1);
       }
       void addEdge(int a, int b, int wt)
       {
              edges.PB({{a, b}, wt});
       }
       int find(int a)
       {
              if (parents[a] == -1)
                     return a;
              return parents[a] = find(parents[a]);
       }
       void unite(int a, int b)
       {
              if (ranks[a] > ranks[b])
              {
                     parents[b] = a;
                     ranks[a] += ranks[b];
              }
              else
              {
                     parents[a] = b;
                     ranks[b] += ranks[a];
              }
       }
       int kruskal()
       {
              int ans = 0;
              sort(edges.begin(), edges.end(), comp);
              for (auto x : edges)
              {
                     int a = x.fi.fi;
                     int b = x.fi.se;
                     int wt = x.se;
                     int s1 = find(a);
                     int s2 = find(b);
                     if (s1 != s2)
                     {
                            unite(s1, s2);
                            ans += wt;
                            cout << a << "----" << b << endl;
                     }
              }
              return ans;
       }
       int prims()
       {
              vector<vector<PII>> adj(V + 1);
              for (auto x : edges)
              {
                     int a = x.fi.fi;
                     int b = x.fi.se;
                     int wt = x.se;
                     adj[a].PB({b, wt});
                     adj[b].PB({a, wt});
              }
              priority_queue<PII, VPII, mycomp> pq;
              VI vis(V + 1, 0);
              vis[2] = 1;
              for (auto x : adj[2])
              {
                     int vertex = x.fi;
                     int wt = x.se;
                     //pq.push(x);
                     pq.push({vertex, wt});
              }
              int ans = 0;
              while (!pq.empty())
              {
                     auto u = pq.top();
                     pq.pop();
                     int currVert = u.fi;
                     int wt = u.se;
                     if (!vis[currVert])
                     {
                            vis[currVert] = 1;
                            cout << currVert << "--->";
                            ans += wt;
                            for (auto y : adj[currVert])
                            {
                                   int vertex = y.fi;
                                   int wt = y.se;
                                   pq.push({vertex, wt});
                            }
                     }
              }
              cout << endl;
              return ans;
       }
};
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
#ifndef ONLINE_JUDGE
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
#endif
       int vert, E;
       cin >> vert >> E;
       graph *g = new graph(vert);
       for (int i = 0; i < E; i++)
       {
              int a, b, wt;
              cin >> a >> b >> wt;
              g->addEdge(a, b, wt);
       }
       cout << g->prims() << endl;

       return 0;
}