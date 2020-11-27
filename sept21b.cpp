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
MSETI nodes;
VVI cnt;
map<int,VI> adj;
int ans=INT64_MAX;
void FindShortestDistanceShubham(int u,int v)
{
       int start=u;
       map<int,int> dis;
       map<int,bool> vis;
       dis[start]=0;
       queue<int> q;
       q.push(start);
       vis[start]=true;
       // for(auto x:adj)
       // {
       //        cout<<x.first<<"-->";
       //        for(auto y:x.se)
       //               cout<<y<<" ";
       //        cout<<endl;
       // }
       // cout<<endl;
       while(!q.empty())
       {
              int curr = q.front();
              q.pop();
              for(auto x:adj[curr])
              {
                     if(!vis[x])
                     {
                            vis[x]=true;
                            q.push(x);
                            if(dis.count(x))
                            {
                                   dis[x]=min(dis[x],dis[curr]+1);
                            }
                            else
                                   dis[x]=dis[curr]+1;
                     }
              }
              
       }
       // for(auto x:dis)
       // {
       //        cout<<x.fi<<"  "<<x.se<<endl;
       // }
       if(vis[v]==true)
              ans=min(ans,dis[v]+1);
}
void FindCycleShubham()
{
       for(auto x:adj)
       {
              map<int,bool> flag;
              for(auto y:x.se)
                     flag[y]=false;
              for(auto y:x.se)
              {
                     if(flag[y]==true)
                            continue;
                     int u=x.fi;
                     int v=y;
                     adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
                     adj[v].erase(find(adj[v].begin(),adj[v].end(),u));
                     flag[y]=true;
                     FindShortestDistanceShubham(u,v);
                     adj[u].PB(v);
                     adj[v].PB(u);
              }
              //cout<<endl;
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
       //nodes.resize(n);
       cnt.resize(65);
       for(int i=0;i<n;i++)
       {
              int a;
              cin>>a;
              nodes.insert(a);
       }
       for(auto x:nodes)
       {
              for(int i=0;i<65;i++)
              {
                     if(x&(1LL<<i))
                     {
                            // if(cnt[i].size()>=3)
                            // {
                            //        cout<<"-1";
                            //        return 0;
                            // }
                            //if(find(cnt[i].begin(),cnt[i].end(),x)==cnt[i].end())
                            cnt[i].PB(x);
                     }
              }
       }
       for(int i=0;i<65;i++)
       {
              if(cnt[i].size()>=3)
              {
                     cout<<"3";
                     return 0;
              }
       }
       for(int i=0;i<65;i++)
       {
              // cout<<"Nos where i-th bit "<<i<<" is set are:";
              // for(auto x:cnt[i])
              // {
              //        cout<<x<<" ";
              // }
              // cout<<endl;
              if(cnt[i].size()==2)
              {
                     int a=cnt[i][0];
                     int b=cnt[i][1];
                     if(find(adj[a].begin(),adj[a].end(),b)==adj[a].end())
                     {
                            adj[a].PB(b);
                            adj[b].PB(a);
                     }
                     
              }
       }
       // for(auto x:adj)
       // {
       //        cout<<x.first<<"-->";
       //        for(auto y:x.se)
       //               cout<<y<<" ";
       //        cout<<endl;
       // }
       FindCycleShubham();
       if(ans==INT64_MAX || ans==1)
              cout<<"-1";
       else
              cout<<ans;
       return 0;
}