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
template<typename T> 
class Graph{
       public:
              int v;
              Graph(int ver)
              {
                     this->v=ver;
              }
              unordered_map<T,vector<T>> adj;
              void addEdge(T a, T b)
              {
                     adj[a].PB(b);
                     adj[b].PB(a);
              }
              void BFS(T src)
              {
                     map<T,int> visited;
                     queue<T> q;
                     q.push(src);
                     visited[src]=1;
                     while(!q.empty())
                     {
                            auto u=q.front();
                            q.pop();
                            cout<<u<<" ";
                            for(auto x:adj[u])
                            {
                                   if(!visited[x])
                                   {
                                          visited[x]=1;
                                          q.push(x);
                                   }
                            }
                     }
              }
              void CalculateShortestDistance(T src)
              {
                     unordered_map<T, int> dis;
                     unordered_map<T, T> parent;
                     for(auto x:adj)
                     {
                            dis[x.fi]=INT64_MAX;
                     }
                     dis[src]=0;
                     queue<T> q;
                     q.push(src);
                     while(!q.empty())
                     {
                            auto u=q.front();
                            cout<<u<<" ";
                            q.pop();
                            for(auto v:adj[u])
                            {
                                   if(dis[v]==INT64_MAX)
                                   {
                                          dis[v]=dis[u]+1;
                                          parent[v]=u;
                                          q.push(v);
                                   }
                            }
                     }
                     cout<<endl;
                     cout<<"distance from "<<src<<" to \n"; 
                     for(auto x:dis)
                     {
                            cout<<x.fi<<" --> "<<x.se<<endl;
                     }
                     T dest = "chennai";
                     while(dest!=src)
                     {
                            cout<<dest<<"<---";
                            dest=parent[dest];
                     }
                     cout<<src<<endl;
              }
};
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int v,e;
       cin>>v>>e;
       Graph<string> G(v);
       for(int i=0;i<e;i++)
       {
              string a,b;
              cin>>a>>b;
              G.addEdge(a,b);
       }
       //G.BFS("mum");
       G.CalculateShortestDistance("bang");
       return 0;
}