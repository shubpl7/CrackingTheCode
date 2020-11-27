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
VI vis;
VI CycleSizes;
int Length;
void DFS(int u)
{
       //cout<<"DFS "<<u<<endl;
       if(vis[u]==1)
              return;
       vis[u]=1;
       Length++;
       for(auto x:adj[u])
              DFS(x);
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
       for(int i=1;i<=n;i++)
       {
              if(!vis[i])
              {
                     Length=0;
                     DFS(i);
                     CycleSizes.PB(Length);
              }
       }
       int sum=0;
       sort(CycleSizes.begin(),CycleSizes.end(),greater<int>());
       for(auto x:CycleSizes)
       {
             //cout<<x<<" ";
              sum+=(x*x);
       }
       //cout<<endl;
       if(CycleSizes.size()>=2)
              sum+=(2*CycleSizes[0]*CycleSizes[1]);
       cout<<sum;
       return 0;
}