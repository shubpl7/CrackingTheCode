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
VI adj[N];
VI adjTranspose[N];
int n,m;
VI dis(N);
void BFS(int src)
{
       for(int i=1;i<=n;i++)
              dis[i]=INT64_MAX;
       dis[src]=0;
       queue<int> q;
       q.push(src);
       while(!q.empty())
       {
              auto u=q.front();
              q.pop();
              for(auto x:adjTranspose[u])
              {
                     if(dis[x]==INT64_MAX)
                     {
                            dis[x]=dis[u]+1;
                            q.push(x);
                     }
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
       cin>>n>>m;
       for(int i=0;i<m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adjTranspose[v].PB(u);
       }
       int k;
       cin>>k;
       VI paths(k);
       for(auto &x :paths)
              cin>>x;
       BFS(*paths.rbegin());
       int alp=0,beta=0;
       for(int i=0;i<k-1;i++)
       {
              int v=paths[i];
              int u=paths[i+1];
              //int alp=0,beta=0;
              if(dis[u]>dis[v]-1)
                     alp++;
              else
              {
                     for(auto x:adj[v])
                     {
                            if(x==u)
                                   continue;
                            if(dis[x]==dis[u])
                            {
                                   beta++;
                                   break;
                            }
                     }
              }
              
       }
       cout<<alp<<" "<<alp+beta;
       return 0;
}