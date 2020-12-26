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
VVI adj;
VVI memo;
int tsp(int mask,int CurrCity)
{
       if(memo[mask][CurrCity]!=-1)
              return memo[mask][CurrCity];
       cout<<"tsp--->"<<mask<<" "<<CurrCity<<endl;
       if(mask==((1<<n)-1)){
              memo[mask][CurrCity]=adj[CurrCity][0];
              return adj[CurrCity][0];
       }
       int ans = INT64_MAX;
       for(int j=0;j<n;j++)//check if the j-th city is vis. or not
       {
              if((mask & (1<<j))==0)
              {
                     int newMask = mask | (1<<j);
                     ans = min(ans,adj[CurrCity][j]+tsp(newMask,j));
              }
       }
       memo[mask][CurrCity]=ans;
       return ans;
}

int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       cin>>m>>n;
       adj.resize(n,VI(n,INT64_MAX));
       memo.resize(1<<n,VI(n,-1));
       for(int i=1;i<=m;i++)
       {
              int u,v,w;
              cin>>u>>v>>w;
              adj[u][v]=w;
              adj[v][u]=w;
       }
       cout<<tsp(1,0);
       return 0;
}