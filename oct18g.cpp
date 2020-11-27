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
int n;
VVI adj;
VI A;
void dfs(int u,int fac)
{
       if(fac%2==0)
              A[u]=1;
       else
              A[u]=2;
       for(auto x:adj[u])
              if(A[x]==-1)
                     dfs(x,fac+1);
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              cin>>n;
              adj.resize(n+1);
              A.resize(n+1,-1);
              for(int i=1;i<=n-1;i++)
              {
                     int u,v;
                     cin>>u>>v;
                     adj[u].PB(v);
                     adj[v].PB(u);
              }
              dfs(1,0);
              for(int i=1;i<=n;i++)
                     cout<<A[i]<<" ";
              cout<<endl;
              adj.clear();
              A.clear();
       }
       return 0;
}