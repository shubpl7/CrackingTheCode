//multi-source prims algorithm
//https://www.spoj.com/problems/IITWPC4I/
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
vector<vector<PII>> adj;
VI vis;
class mycomp{
       public:
              bool operator()(const PII &a,const PII &b)
              {
                     return a.fi>b.fi;
              }
};
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              int n,m;
              cin>>n>>m;
              adj.resize(n+1);
              vis.resize(n+1,false);
              priority_queue<PII,VPII,mycomp> pq;
              VI milkman(n+1);
              for(int i=1;i<=n;i++)
              {
                     cin>>milkman[i];
              }
              for(int i=0;i<m;i++)
              {
                     int u,v,c;
                     cin>>u>>v>>c;
                     adj[u].PB({v,c});
                     adj[v].PB({u,c});

              }
              for(int i=1;i<=n;i++)
              {
                     if(milkman[i])
                     {
                            vis[i]=1;
                            for(auto x:adj[i])
                            {
                                   pq.push({x.se,x.fi});
                            }
                     }
              }
              int ans=0;
              while(!pq.empty())
              {
                     auto x = pq.top();
                     pq.pop();
                     if(!vis[x.se])
                     {
                            vis[x.se]=1;
                            ans+=x.fi;
                            for(auto y:adj[x.se])
                            {
                                   pq.push({y.se,y.fi});
                            }
                     }
              }
              bool flag=false;
              for(int i=1;i<=n;i++)
              {
                     if(!vis[i])
                            flag=true;
              }
              if(flag)
                     cout<<"impossible\n";
              else
                     cout<<ans<<endl;
              adj.clear();
              vis.clear();
       }

       return 0;
}