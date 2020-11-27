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
const int N = 2e5+5;
VI adj[N];
int n,m;
VI vis(N,-1);
void BFS()
{
       queue<pair<int,int>> q;
       q.push({1,1});
       vis[1]=1;
       while(!q.empty())
       {
              auto u=q.front();
              q.pop();
              int currVertex=u.fi;
              int currColor=u.se;
              for(auto x:adj[currVertex])
              {
                     if(vis[x]==-1)
                     {
                            vis[x]=3-currColor;
                            //vis[x]=currColor%2+1;
                            q.push({x,vis[x]});
                     }
                     else if(vis[x]==currColor)
                     {
                            cout<<"Vertex "<<currVertex<<" and "<<x<<" have the same color: "<<currColor<<endl;
                            return;
                     }
              }
       }
       cout<<"the graph is Bi-partite";
}
void Bipartite()
{
       int src=1;
       BFS();
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
       for(int i=0;i<m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adj[v].PB(u);
       }
       Bipartite();
       return 0;
}