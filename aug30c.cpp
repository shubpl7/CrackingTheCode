#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
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
VVI adj;
VI vis;
VI str;
void DFS(int x,int &count)
{
       vis[x]=1;
       count+=str[x];
       vector<int>::iterator it=adj[x].begin();
       for(;it!=adj[x].end();it++)
       {
              if(!vis[*it])
              {
                     DFS(*it,count);
              }
       }
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
       adj.resize(n+1);
       vis.resize(n+1,0);
       str.resize(n+1);
       for(int i=0;i<m;i++)
       {
              int a,b;
              cin>>a>>b;
              adj[a].PB(b);
              adj[b].PB(a);
       }
       for(int i=1;i<=n;i++)
              cin>>str[i];
       int ans=0;
       for(int i=1;i<=n;i++)
       {
              if(!vis[i])
              {
                     int count=0;
                     DFS(i,count);
                     ans=max(ans,count);
              }
       }
       cout<<ans;
       return 0;
}