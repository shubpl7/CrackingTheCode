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
VVI adj;
int n;
unordered_set<int> set1,set2;
void DFS(int u,int par,int color)
{
       //cout<<"DFS "<<u<<" "<<par<<" "<<color<<endl;
       if(color==1)
              set1.insert(u);
       else
              set2.insert(u);
       for(auto x:adj[u])
       {
              if(x==par)
                     continue;
              DFS(x,u,(color)%2+1);
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
       cin>>n;
       adj.resize(n+1);
       for(int i=1;i<=n-1;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adj[v].PB(u);
       }
       int color=1;
       DFS(1,-1,color);
       int ans=0;
       int sizeof2 = set2.size();
       for(auto x:set1)
       {
              ans+=(sizeof2-(int)adj[x].size());
       }
       cout<<ans;
       return 0;
}