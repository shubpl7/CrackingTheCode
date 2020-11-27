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
int n,m;
map<char,vector<pair<char,int>>> adj;
unordered_map<char,int> dis;
void dijkstra(char src)
{
       for(auto x:adj)
       {
              dis[x.fi]=INT64_MAX;
       }
       set<pair<char,int>> s;
       s.insert({0,src});
       dis[src]=0;
       while(!s.empty())
       {
              auto u = *s.begin();
              s.erase(s.begin());
              char currcity= u.se;
              int currdis=u.fi;
              for(auto x:adj[currcity])
              {
                     if(dis[x.fi]>dis[currcity]+x.se)
                     {
                            if(dis[x.fi]!=INT64_MAX)
                            {
                                   s.erase(s.find({dis[x.fi],x.fi}));
                            }
                            dis[x.fi]=dis[currcity]+x.se;
                            s.insert({dis[x.fi],x.fi});
                     }
              }
       }
       for(auto x:dis)
       {
              cout<<x.fi<<" "<<x.se<<endl;
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
              char s,t;
              int wt;
              cin>>s>>t>>wt;
              adj[s].PB({t,wt});
       }
       dijkstra('b');
       return 0;
}