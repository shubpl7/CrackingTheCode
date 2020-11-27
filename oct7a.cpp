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
class Graph{
       public:
              int v;
              unordered_map<string,vector<pair<string,int>>> adj;
              Graph(int vert)
              {
                     this->v=vert;
                     //adj.resize(vert);
              }
              void AddEdge(string u, string v,int wt)
              {
                     adj[u].push_back({v,wt});
                     adj[v].PB({u,wt});
              }
              void PrintGraph()
              {
                     for(auto pair:adj)
                     {
                            string sourceCity = pair.fi;
                            cout<<"neighbours of "<<sourceCity<<" are : ";
                            for(auto x:pair.se)
                            {
                                   cout<<"{ "<<x.fi<<", "<<x.se<<" }  ";
                            }
                            cout<<endl;
                     }
              }
              void BFS(string src)
              {
                     map<string,int > vis;
                     map<string,int> dis;
                     dis[src]=0;
                     vis[src]=1;
                     queue<string> q;
                     q.push(src);
                     while(!q.empty())
                     {
                            string u = q.front();
                            q.pop();
                            for(auto x: adj[u])
                            {
                                   string v = x.fi;
                                   if(!vis[v])
                                   {
                                          dis[v]=dis[u]+1;
                                          vis[v]=1;
                                          q.push(v);
                                   }
                            }

                     }

                     for(auto x:dis)
                     {
                            cout<<x.fi<<" "<<x.se<<endl;
                     }

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
       Graph G(v);
       for(int i=0;i<e;i++)
       {
              string a,b;
              int c;
              cin>>a>>b;
              cin>>c;
              G.AddEdge(a,b,c);
       }
       G.PrintGraph();
       G.BFS("0");
       return 0;
}