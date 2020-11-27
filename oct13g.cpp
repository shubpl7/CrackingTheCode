#include<bits/stdc++.h>
//Finding cycle in undirected graph
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
VVI adj;
VI vis,depth;
int CycleSize;
int n,e;
int ans=0;
void DFS(int curr,int par,int level)
{
       cout<<"DFS "<<curr<<" "<<par<<" "<<level<<endl; 
       depth[curr]=level;
       //vis[curr]=true;
       for(auto x:adj[curr])
       {
              if(x==par)
                     continue;
              if(depth[x]!=-1)
              {
                     CycleSize=abs(depth[x]-depth[curr]);
                     cout<<"Cycle found between : "<<x<<" and "<<curr<<endl;
                     cout<<"Cycle size is : "<<CycleSize<<endl;
                     ans=1;
                     //ans=true;
                     //continue;
                     // return true;
              }
              else
                     DFS(x,curr,level+1);   
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
       cin>>n>>e;
       adj.resize(n+1);
       vis.resize(n+1,false);
       for(int i=0;i<e;i++)
       {
              int a,b;
              cin>>a>>b;
              adj[a].PB(b);
              adj[b].PB(a);
       }
       depth.resize(n+1,-1);
       DFS(1,-1,0);
       if(!ans)
              cout<<"Cycle not found";
       return 0;
}