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
VI adj[100];
vector<bool> vis;
vector<int> route;
int n,m;
bool IsCycle(int src)
{
       vis[src]=true;
       route[src]=1;
       // cout<<"DFS "<<src<<"-->";
       // for(int i=1;i<=n;i++)
       // {
       //        if(route[i])
       //               cout<<i<<" ";
       // }
       // cout<<endl;
       for(auto x:adj[src])
       {
              if(vis[x]==false)
              {
                     bool subproblm = IsCycle(x);
                     if(subproblm)
                     {
                            return true;
                     }
              }
              else if(vis[x]==true and route[x]==1)
              {
                     return true;
              }
       }
       cout<<"DFS "<<src<<"-->";
       for(int i=1;i<=n;i++)
       {
              if(route[i])
                     cout<<i<<" ";
       }
       cout<<endl;
       route[src]=0;
       return false;

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
       vis.resize(n+1,false);
       for(int i=0;i<m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
       }
       route.resize(n+1,0);
       if(IsCycle(1))
              cout<<"Cycle found";
       else
              cout<<"Not found";
       return 0;
}