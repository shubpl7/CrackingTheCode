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
class mycomp{
       public:
              bool operator()(const PII &a,const PII &b)
              {
                     return b.fi<a.fi;
              }
};
vector<vector<pair<int,int>>> adj;
int n,m;
void dijkstra()
{
       VI dis(n+1,INT64_MAX);
       VI parent(n+1,-1);
       priority_queue<PII,VPII,mycomp> pq;
       int src=1;
       dis[src]=0;
       pq.push({dis[src],src});
       while(!pq.empty())
       {
              auto u=pq.top();
              cout<<u.fi<<" "<<u.se<<endl;
              pq.pop();
              int currdistance=u.fi;
              int currVertex = u.se;
              for(auto x:adj[currVertex])
              {
                     int neighCity = x.fi;
                     int wt = x.se;
                     if(dis[neighCity]>dis[currVertex]+wt)
                     {
                            dis[neighCity]=dis[currVertex]+wt;
                            parent[neighCity]=currVertex;
                            pq.push({dis[neighCity],neighCity});
                     }
              }
       }
       for(int i=2;i<=n;i++)
       {
              int dest=i;
              while(dest!=src)
              {
                     cout<<dest<<"<--";
                     dest=parent[dest];
              }
              cout<<src;
              cout<<"    dist is : "<<dis[i]<<endl;
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
       adj.resize(n+1);
       for(int i=0;i<m;i++)
       {
              int u,v,wt;
              cin>>u>>v>>wt;
              adj[u].PB({v,wt});
       }
       dijkstra();
       return 0;
}