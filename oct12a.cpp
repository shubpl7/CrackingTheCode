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
              Graph(int ver)
              {
                     this->v=ver;
              }
              void AddEdge(string u,string v,int wt)
              {
                     adj[u].PB({v,wt});
                     adj[v].PB({u,wt});
              }
              void PrintGraph()
              {
                     for(auto x:adj)
                     {
                            cout<<x.fi<<"--> neighbours are : ";
                            for(auto y:x.se)
                            {
                                   cout<<"{ "<<y.fi<<" "<<y.se<<" }";
                            }
                            cout<<endl;
                     }
                     //     O(Vertices + Edges)
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
       return 0;
}