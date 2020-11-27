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
VI adj[100];
vector<bool> vis(100);
VI currentpath;
bool isCycle(int src)
{
       vis[src]=true;
       currentpath[src]=1;
       cout<<"DFS "<<src<<"-->";
       for(int i=1;i<=n;i++)
       {
              if(currentpath[i])
                     cout<<i<<" ";
       }
       cout<<endl;
       for(auto x:adj[src])
       {
              if(!vis[x])
              {
                     bool subproblem = isCycle(x);
                     if(subproblem==true)
                            return true;
              }
              else if(vis[x]==true and currentpath[x])
              {
                     return true;
              }
       }
       // cout<<"DFS "<<src<<"-->";
       // for(int i=1;i<=n;i++)
       // {
       //        if(currentpath[i])
       //               cout<<i<<" ";
       // }
       // cout<<endl;
       currentpath[src]=0;
       return false;
}
void BFS()
{
       //kahn's alogorithm of finding tpological sort uing BFS
       VI indegree(n+1,0);
       for(auto x:adj)
       {
              for(auto y:x)
                     indegree[y]++;
       }
       queue<int> q;
       for(int i=1;i<=n;i++)
       {
              if(indegree[i]==0)
                     q.push(i);
       }
       while(!q.empty())
       {
              int u=q.front();
              q.pop();
              cout<<u<<" ";
              for(auto x:adj[u])
              {
                     indegree[x]--;
                     if(indegree[x]==0)
                            q.push(x);
              }
       }
}
void DFS(int src, stack<int> &s)
{
       vis[src]=true;
       for(auto x:adj[src])
       {
              if(!vis[x])
                     DFS(x,s);
       }
       s.push(src);
}
void topologicalSort()
{
       // stack<int> s;
       // for(int i=0;i<n;i++)
       // {
       //        if(!vis[i])
       //               DFS(i,s);
       // }
       // while(!s.empty())
       // {
       //        cout<<s.top()<<" ";
       //        s.pop();
       // }
       BFS();
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
       for(int i=0;i<m;i++)
       {
              int u,v;
              cin>>u>>v;
              adj[u].PB(v);
       }
       topologicalSort();
       // vis.resize(n+1,false);
       // currentpath.resize(n+1,0);
       // if(isCycle(1))
       //        cout<<"Cycle found\n";
       // else
       //        cout<<"No cycle\n";
       return 0;
}