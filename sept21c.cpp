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
VVI AdjTrain,AdjBus;
int ComputeShortestDistance(VVI &adj)
{
       VI dis(n+1,INT64_MAX);
       vector<bool> vis(n+1,false);
       int start=1;
       dis[start]=0;
       vis[start]=true;
       queue<int> q;
       q.push(start);
       while(!q.empty())
       {
              int u = q.front();
              q.pop();
              for(auto v:adj[u])
              {
                     if(!vis[v])
                     {
                            vis[v]=true;
                            dis[v]=min(dis[v],dis[u]+1);
                            q.push(v);
                     }
              }
       }
       return dis[n];

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
       AdjTrain.resize(n+1);
       AdjBus.resize(n+1);
       set<pair<int,int>> rail;
       for(int i=0;i<m;i++)
       {
              int a,b;
              cin>>a>>b;
              AdjTrain[a].PB(b);
              AdjTrain[b].PB(a);
              rail.insert({a,b});
              rail.insert({b,a});
       }
       for(int i=1;i<=n;i++)
       {
              for(int j=1;j<=n;j++)
              {
                     if(i==j)
                            continue;
                     if(rail.find({i,j})==rail.end())
                     {
                            AdjBus[i].PB(j);
                            AdjBus[j].PB(i);
                     }
              }
       }
       if(rail.find({1,n})!=rail.end())
       {
              //it means there is a railway station between 1..n;
              int ans = ComputeShortestDistance(AdjBus);
              if(ans==INT64_MAX)
                     cout<<"-1";
              else
                     cout<<max(1LL,ans);

       }
       else
       {
              //it means there is a road between 1..n;
              int ans = ComputeShortestDistance(AdjTrain);
              if(ans==INT64_MAX)
                     cout<<"-1";
              else
                     cout<<max(1LL,ans);
       }
       
       return 0;
}