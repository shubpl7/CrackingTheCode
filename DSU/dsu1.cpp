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
       int V;
       //VVI adj;
       VPII edges;
       VI parent;
       public:
              Graph(int vert)
              {
                     this->V=vert;
                     // edges.resize(V);
                     parent.resize(V,-1);
              }
              void addEdge(int a,int b)
              {
                     edges.PB({a,b});
              }
              int find(int a)
              {
                     if(parent[a]==-1)
                            return a;
                     return find(parent[a]);
              }
              bool FindCycle()
              {
                     for(auto edge : edges)
                     {
                            int a=edge.fi;
                            int b=edge.se;
                            int s1=find(a);
                            int s2=find(b);
                            if(s1!=s2)
                            {
                                   parent[s2]=s1;
                            }
                            else
                            {
                                   cout<<"Cycle Found\n";
                                   cout<<s1<<" "<<s2<<endl;
                                   return true;
                            }
                            
                     }
                     cout<<"No Cycle\n";
                     return false;
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
       Graph *g = new Graph(4);
       g->addEdge(0,1);
       g->addEdge(1,2);
       g->addEdge(2,3);
       //g->addEdge(3,0);
       cout<<g->FindCycle();
       return 0;
}