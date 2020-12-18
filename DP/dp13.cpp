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
VI maxh;
int n;
int LongestPath=0;
void DFS2(int u,int par)
{
       if(adj[u].size()==1)
       {
              LongestPath=max(LongestPath,maxh[u]);
       }
       else
       {
              multiset<int> s;
              for(auto x:adj[u])
              {
                     if(x==par)
                            continue;
                     s.insert(maxh[x]);
              }
              if(s.size()>1){
              auto it=s.rbegin();
              int LargestChildren = *it;
              it++;
              int SecondLargestChildren=*it;
              LongestPath=max(LongestPath,2+LargestChildren+SecondLargestChildren);
              }
       }
       for(auto y:adj[u])
       {
              if(y!=par)
                     DFS2(y,u);
       }
       
}
int DFS1(int u,int par)//return the height of sub-tree rooted at u
{
       int MaxChildrenHeight=-1;
       for(auto x:adj[u])
       {
              if(x==par)
                     continue;
              int h= DFS1(x,u);
              if(h>MaxChildrenHeight)
                     MaxChildrenHeight=h;
       }
       maxh[u]=MaxChildrenHeight+1;
       return MaxChildrenHeight+1;
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
       maxh.resize(n+1);
       for(int i=1;i<=n-1;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
              adj[v].PB(u);
       }
       DFS1(1,-1);
       
       DFS2(1,-1);
       // for(int i=1;i<=n;i++)
       //        cout<<maxh[i]<<" ";
       cout<<LongestPath;
       return 0;
}