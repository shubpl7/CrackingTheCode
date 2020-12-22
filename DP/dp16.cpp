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
VI val;
VI parent;
int ans=0;
PII DFS(int u, int par)
{
       int maxi=INT64_MIN, mini = INT64_MAX;
       bool flag=0;
       for(auto x:adj[u])
       {
              if(x==par)
                     continue;//leaf
              flag=1;
              //non-leaf nodes 
              auto child = DFS(x,u);
              maxi = max(maxi,child.first);
              mini = min(mini,child.second);
       }
       if(flag==0)
              maxi=val[u],mini = val[u];
       int currmax = max(abs(val[u]-maxi),abs(val[u]-mini));
       if(currmax>ans)
              ans=currmax;
       maxi=max(maxi,val[u]);
       mini=min(mini,val[u]);
       //cout<<"DFS-->"<<u<<" "<<maxi<<" "<<mini<<endl;
       return {maxi,mini};
       
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       cin>>n;
       adj.resize(n+1);
       val.resize(n+1);
       parent.resize(n+1);
       for(int i=1;i<=n;i++)
       {
              cin>>val[i];
       }
       int root=0;
       for(int i=1;i<=n;i++)
       {
              cin>>parent[i];
              if(parent[i]==-1)
                     root=i;
              else
              {
                     adj[i].PB(parent[i]);
                     adj[parent[i]].PB(i);
              }
       }
       DFS(root,-1);
       cout<<ans;
       return 0;
}