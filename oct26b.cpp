#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
//checking whether a graph is bi-partite or not
const int N=2e5+5;
VVI adj;
int n,m;
VI vis(N,-1);
bool BFS(int src)
{
       queue<PII> q;
       q.push({src,1});
       vis[src]=1;
       while(!q.empty())
       {
              auto v=q.front();
              int currVertex = v.fi;
              int currColor = v.se;
              q.pop();
              for(auto x:adj[currVertex])
              {
                     if(vis[x]==-1)
                     {
                            q.push({x,3-currColor});
                            vis[x]=3-currColor;
                     }
                     else if(vis[x]==vis[currVertex])
                            return false;
              }
       }
       return true;
}

bool DFS(int u,int par, int col)
{
       vis[u]=col;
       for(auto x:adj[u])
       {
              if(vis[x]==-1)
              {
                     bool subproblm = DFS(x,u,3-col);
                     if(subproblm==false)
                            return false;
              }
              else if(x!=par and vis[x]==vis[u])
              {
                     cout<<"vertex "<<x<<" and "<<u<<" have same color "<<col<<endl;
                     return false;
              }
       }
       return true;
}
void CheckForBiPartite()
{
       int src=1;
       int col=1;
       int par=-1;
       //DFS(src,par,col)
       if(BFS(src))
              cout<<"Yes, the graph is bi-partite\n";
       else
              cout<<"No, Not a bi-partite graph\n";
       for(int i=1;i<=n;i++)
              cout<<vis[i]<<" ";
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n>>m;
       adj.resize(n+1);
       for(int i=1;i<=m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adj[v].PB(u);
       }
       CheckForBiPartite();
       return 0;
}