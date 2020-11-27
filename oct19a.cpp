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
int n,m,k;
VI colors;
// vector<set<int>> adj;
VVI adj;
VI vis;
int sizeofComp;
VI CompColors;
void dfs(int u)
{
       //cout<<"dfs "<<u<<endl;
       vis[u]=1;
       sizeofComp++;
       CompColors.PB(colors[u]);
       for(auto x:adj[u])
              if(!vis[x])
                     dfs(x);
       
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       cin>>n>>m>>k;
       colors.resize(n+1);
       vis.resize(n+1,0);
       for(int i=1;i<=n;i++)
       {
              cin>>colors[i];
       }
       adj.resize(n+1);
       for(int i=0;i<m;i++)
       {
              int l,r;
              cin>>l>>r;
              adj[l].PB(r);
              adj[r].PB(l);
       }
       int ans=0;
       for(int i=1;i<=n;i++)
       {
              if(!vis[i])
              {
                     sizeofComp = 0;
                     dfs(i);
                     sort(CompColors.begin(),CompColors.end());
                     int maxrep=1,rep=1;
                     //if(CompColors.size)
                     for(int i=0;i<CompColors.size()-1;i++)
                     {
                            if(CompColors[i]==CompColors[i+1])
                            {
                                   rep++;
                                   
                            }
                            else
                            {
                                   rep=1;
                            }
                            maxrep=max(maxrep,rep);

                     }
                     ans+=(sizeofComp-maxrep);
                     // for(auto x:CompColors)
                     // {
                     //        cout<<x<<" ";
                     // }
                     // cout<<endl;
                     // cout<<sizeofComp<<" "<<maxrep<<endl;
                     CompColors.clear();
              }
       }
       cout<<ans;
       return 0;
}