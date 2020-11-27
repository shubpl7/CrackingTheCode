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
VVI adj;
VI vis;
VI color;
int sizeofComp;
VI ComponentColors;
void DFS(int u)
{
       vis[u]=1;
       ComponentColors.PB(color[u]);
       sizeofComp++;
       for(auto x:adj[u])
              if(!vis[x])
                     DFS(x);
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
       adj.resize(n+1);
       vis.resize(n+1,0);
       color.resize(n+1);
       for(int i=1;i<=n;i++)
              cin>>color[i];
       for(int i=0;i<m;i++)
       {
              int l,r;
              cin>>l>>r;
              adj[l].PB(r);
              adj[r].PB(l);
       }
       int total=0;
       for(int i=1;i<=n;i++)
       {
              if(!vis[i])
              {
                     sizeofComp=0;
                     DFS(i);
                     sort(ComponentColors.begin(),ComponentColors.end());
                     int maxrep=1,rep=1;
                     for(int i=0;i<ComponentColors.size()-1;i++)
                     {
                            if(ComponentColors[i]==ComponentColors[i+1])
                            {
                                   rep++;
                            }
                            else
                                   rep=1;
                            maxrep=max(maxrep,rep);
                     }
                     total+=(sizeofComp-maxrep);
                     ComponentColors.clear();

              }
       }
       cout<<total;
       return 0;
}