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
int n;
VVI adj;
VI vis;
int CycleLength;
void DFS(int u)
{
       if(vis[u])
              return;
       CycleLength++;
       vis[u]=1;
       for(auto x:adj[u])
       {
              DFS(x);
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
       int n;
       cin>>n;
       adj.resize(n+1);
       vis.resize(n+1,0);
       for(int i=1;i<=n;i++)
       {
              int a;
              cin>>a;
              adj[i].PB(a);
       }
       VI cycles;
       for(int i=1;i<=n;i++)
       {
              if(!vis[i])
              {
                     CycleLength = 0;
                     DFS(i);
                     cycles.PB(CycleLength);
              }
       }
       sort(cycles.begin(),cycles.end(),greater<int>());
       int sum=0;
       for(auto x:cycles)
              sum+=(x*x);
       if(cycles.size()>=2)
              sum+=2*cycles[0]*cycles[1];
       cout<<sum;
       return 0;
}