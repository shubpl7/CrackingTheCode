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
vector<pair<int,int>> adj[N];
int n,m;
class mycomp{
       public:
              bool operator()(const PII &a, const PII &b)
              {
                     return b.fi<a.fi;
              }
};
void dijkstra(int src)
{
       priority_queue<PII,VPII,mycomp> pq;
       VI dis(n+1,INT64_MAX);
       VI parent(n+1,-1);
       dis[src]=0;
       parent[src]=-1;
       pq.push({dis[src],src});
       while(!pq.empty())
       {
              auto u=pq.top();
              pq.pop();
              cout<<u.fi<<" "<<u.se<<endl;
              int currCity=u.se;
              int currDis=u.fi;
              for(auto x:adj[currCity])
              {
                     int neighbourCity= x.fi;
                     int wt=x.se;
                     if(dis[neighbourCity]>dis[currCity]+wt)
                     {
                            parent[neighbourCity]=currCity;
                            dis[neighbourCity]=dis[currCity]+wt;
                            pq.push({dis[neighbourCity],neighbourCity});
                     }
              }
       }
       for(int i=1;i<=n;i++)
       {
              cout<<dis[i]<<" ";
       }
       cout<<endl;
       for(int i=2;i<=n;i++)
       {
              int dest=i;
              while(dest!=src)
              {
                     cout<<dest<<"<--";
                     dest=parent[dest];
              }
              cout<<src;
              cout<<" and the total dis from "<<src<<" is: "<<dis[i]<<endl;
              //cout<<endl;
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
              int u,v,wt;
              cin>>u>>v>>wt;
              adj[u].PB({v,wt});
       }
       int src=1;
       dijkstra(src);
       return 0;
}