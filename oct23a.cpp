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
const int N = 2e5+5;
int n,m;
VI adj[N];
VI adjnew[N];
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
              auto u = q.front();
              q.pop();
              for(auto x:adjnew[u])
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
       for(int i=1;i<=m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adjnew[v].PB(u);
       }
       int k;
       cin>>k;
       VI path(k);
       for(auto &x:path)
              cin>>x;
       BFS(*path.rbegin());
       int alp=0,beta=0;
       for(int i=0;i<k-1;i++)
       {
              int u=path[i];
              int v=path[i+1];
              if(dis[v]>dis[u]-1)
                     alp++;
              else
              {
                     for(auto x:adj[u])
                     {
                            if(x==v)
                                   continue;
                            if(dis[x]==dis[u]-1)
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