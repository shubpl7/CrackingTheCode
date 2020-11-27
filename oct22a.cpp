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
int n;
int ans;
int DFS(int src,int par,int edge)
{
       int count=0;
       for(auto x:adj[src])
       {
              if(x.fi==par)
                     continue;
              count+=DFS(x.fi,src,x.se);
       }
       count++;
       if(par!=-1)
       {
              ans+=(2*min(count,n-count)*edge);
       }
       return count;
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
       int ti=0;
       while(t--)
       {
              cin>>n;
              ti++;
              adj.resize(n+1);
              for(int i=1;i<=n-1;i++)
              {
                     int x,y,z;
                     cin>>x>>y>>z;
                     adj[x].PB({y,z});
                     adj[y].PB({x,z});
              }
              ans=0;
              DFS(1,-1,0);
              adj.clear();
              cout<<"Case #"<<ti<<": "<<ans<<endl;

       }
       return 0;
}