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
const int N=2e5+5;
VVI adj;
int n,m;
int levels[N]={0};
void DFS(int src,int par, int &ans,int level){
       levels[src]=level;
       for(auto x: adj[src])
       {
              if(x==par)
                     continue;
              if(levels[x]==0)
              {
                     DFS(x,par,ans, level+1);
              }
              else
              {
                     ans=min(ans,abs(levels[x]-levels[src])+1);
              }
              
       }

}
void FindCycle()
{
       int shortestcycle=INT64_MAX;;
       for(int i=1;i<=n;i++)
       {
              int ans=INT64_MAX;
              DFS(i,-1,ans,1);
              if(ans!=INT64_MAX)
                     shortestcycle=min(shortestcycle,ans);
       }
       cout<<shortestcycle;
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
       FindCycle();
       return 0;
}