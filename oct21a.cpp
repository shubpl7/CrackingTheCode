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
int n,m;
VI IED;
VVI adj;
int attack=0;
void DFS(int src,int par,int currsum)
{
       //cout<<"DFS "<<src<<" "<<par<<" "<<currsum<<"\n";
       if(currsum>m)
              return;
       if(adj[src].size()==1 and src!=1)
       {
              attack++;
              return;
       }
       for(auto x:adj[src])
       {
              if(x==par)
                     continue;
              DFS(x,src,(currsum+1)*IED[x]);              
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
       IED.resize(n+1);
       adj.resize(n+1);
       for(int i=1;i<=n;i++)
       {
              int a;
              cin>>a;
              IED[i]=a;
       }       
       for(int i=1;i<=n-1;i++)
       {
              int x,y;
              cin>>x>>y;
              adj[x].PB(y);
              adj[y].PB(x);
       }
       DFS(1,-1,IED[1]);
       cout<<attack;
       return 0;
}