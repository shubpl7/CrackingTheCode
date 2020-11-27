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
vector<bool> vis;
int cnt=0;
void DFS(int u)
{
       //cout<<"DFS "<<u<<" "<<cnt<<endl; 
       vis[u]=true;
       cnt++;
       for(auto x:adj[u])
       {
              if(!vis[x])
              {
                     DFS(x);
              }
       }
}
VPII findcritical(int n,int m, VPII edges)//n is no of warehouses, m is no of roads
{
       VPII ans;
       vis.resize(n+1,false);
       adj.resize(n+1);
       for(auto x:edges)
       {
              int a=x.fi;
              int b=x.se;
              adj[a].PB(b);
              adj[b].PB(a);
       }

       for(int i=1;i<=n;i++)
       {
              map<int,int> flag;
              for(auto y:adj[i])
                     flag[y]=false;
              for(auto y:adj[i])
              {
                     if(flag[y])
                            continue;
                     
                     adj[i].erase(find(adj[i].begin(),adj[i].end(),y));
                     adj[y].erase(find(adj[y].begin(),adj[y].end(),i));
                     
                     for(int i=1;i<=n;i++)
                            vis[i]=false;
                     cnt=0;
                     DFS(y);
                     //cout<<"Value of cnt: "<<cnt<<" "<<endl;
                     int f1=0;
                     if(cnt!=n)
                     {
                            for(int j=0;j<ans.size();j++)
                            {
                                   if((ans[j].first==i && ans[j].se==y) || (ans[j].first==y && ans[j].se==i))
                                   {
                                          f1=1;
                                          break;
                                   }       

                            }
                            if(!f1)
                                   ans.PB({min(i,y),max(i,y)});
                     }       
                     flag[y]=true;
                     adj[i].PB(y);
                     adj[y].PB(i);
              }
       }

       return ans;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,m;
       cin>>n>>m;
       VPII edges(m);
       for(int i=0;i<m;i++)
       {
              int a,b;
              cin>>a>>b;
              edges[i]={a,b};
       }
       auto ans=findcritical(n,m,edges);
       for(auto x:ans)
       {
              cout<<x.fi<<" "<<x.se<<endl;
       }
       return 0;
}