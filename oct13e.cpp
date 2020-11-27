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
int n,p;
VVI adj;
vector<bool> vis;
int SizeOFComponent=0;
void DFS(int i)
{
       //cout<<"DFS "<<i<<endl;
       vis[i]=true;
       SizeOFComponent++;
       for(auto x:adj[i])
       {
              if(!vis[x])
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
       cin>>n>>p;
       adj.resize(n);
       vis.resize(n,false);
       for(int i=0;i<p;i++)
       {
              int a,b;
              cin>>a>>b;
              adj[a].PB(b);
              adj[b].PB(a);
       }
       int total= (n*(n-1))/2;
       for(int i=0;i<n;i++)
       {
              if(!vis[i])
              {
                     SizeOFComponent=0;
                     DFS(i);
                     //cout<<SizeOFComponent<<endl;
                     total =total - (SizeOFComponent*(SizeOFComponent-1))/2;
              }
       }
       cout<<total;
       return 0;
}