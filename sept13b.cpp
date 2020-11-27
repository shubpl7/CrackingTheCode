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
vector<vector<pair<int,int>>> adj;
int psum=0,pathtime=0;
void DFS(int u,int par,int max_t,int n,int beauty[],int &ans)
{
       cout<<u<<" "<<par<<" "<<psum<<" "<<pathtime<<" "<<ans<<endl;
       if(2*pathtime>max_t)
       {
              psum=0;
              pathtime=0;
              return;
       }
       if(par==-1)
              psum+=beauty[u];
       for(auto x:adj[u])
       {

              if(x.first!=par)
              {
                     psum+=beauty[x.first];
                     pathtime+=x.second;
                     if(2*pathtime<=max_t)
                     {
                            ans=max(ans,psum);
                     }
                     DFS(x.fi,u,max_t,n,beauty,ans);
              }
              
       }
}
void compute(int n, int m,int max_t,int beauty[],int u[],int v[],int t[])
{
       adj.resize(n);
       for(int i=0;i<m;i++)
       {
              int a=u[i];
              int b=v[i];
              int time=t[i];
              adj[a].push_back({b,time});
              adj[b].push_back({a,time});
       }
       int ans=0;
       DFS(0,-1,max_t,n,beauty,ans);
       cout<<ans;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,m;
       cin>>n>>m;
       int max_t;
       cin>>max_t;
       int beauty[n],u[m],v[m],t[m];
       for(int i=0;i<n;i++)
              cin>>beauty[i];
       for(int i=0;i<m;i++)
              cin>>u[i];
       for(int i=0;i<m;i++)
              cin>>v[i];
       for(int i=0;i<m;i++)
              cin>>t[i];
       compute(n,m,max_t,beauty,u,v,t);
       return 0;
}