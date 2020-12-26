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
int infinity = 1000000000;
int n,m,E;
struct edge{
       int city,wt,ener;
       edge(int v,int w,int e)
       {
              city=v;wt=w;ener=e;
       }
};
int dp[1<<14][14][101];
vector<vector<edge>> adj;
int TSP(int mask,int currCity,int Energy)
{
       //cout<<"TSP-->"<<mask<<" "<<currCity<<" "<<Energy<<endl;
       if(mask==((1<<n)-1))
       {
              if(Energy<0)
                     return infinity;
              return 0;
       }
       //reach here only if mask != 1111(there are still some cities unvisited)
       if(Energy<=0)
       {
              return infinity;
       }
       if(dp[mask][currCity][Energy]!=-1)
              return dp[mask][currCity][Energy];
       int ans=infinity;
       for(auto x:adj[currCity])
       {
              if((mask & (1<<x.city))==0)//x.city is unvisited
              {
                     int newmask = mask | (1<<x.city);
                     ans=min(ans,x.wt+TSP(newmask,x.city,Energy-x.ener));
              }
       }
       dp[mask][currCity][Energy]=ans;
       return ans;

}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       cin>>n>>m>>E;
       adj.resize(n);
       for(int i=1;i<=m;i++)
       {
              int u,v,d,e;
              cin>>u>>v>>d>>e;
              u--;v--;
              edge e1(u,d,e);
              edge e2(v,d,e);
              adj[u].PB(e2);
              adj[v].PB(e1);
       }
       memset(dp,-1,sizeof(dp));
       int ans = TSP(1,0,E);
       if(ans==infinity)
              cout<<"-1";
       else
              cout<<ans;
       return 0;
}