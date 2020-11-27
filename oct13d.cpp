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
int n,e;
unordered_map<char,vector<char>> adj;
void BFS(char src,char dest)
{
       unordered_map<char,int> dis;
       for(auto x:adj)
       {
              char cityName = x.fi;
              dis[cityName]=INT64_MAX;
       }
       unordered_map<char,char> parent;
       queue<char> q;
       q.push(src);
       dis[src]=0;
       while(!q.empty())
       {
              auto u= q.front();
              cout<<u<<" ";
              q.pop();
              for(auto x:adj[u])
              {
                     if(dis[x]==INT64_MAX)
                     {
                            q.push(x);
                            dis[x]=dis[u]+1;
                            parent[x]=u;
                     }
              }
       }
       cout<<"shortest dist. from "<<src<<" to "<<dest<<" is: "<<dis[dest]<<endl;
       while(dest!=src)
       {
              cout<<dest<<"<---";
              dest=parent[dest];
       }
       cout<<src<<endl;
}
unordered_map<char,bool> vis;
void DFS(char src)
{
       cout<<"DFS "<<src<<endl;
       vis[src]=true;
       for(auto x:adj[src])
       {
              if(!vis[x])
              {
                     DFS(x);
              }
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
       cin>>n>>e;
       for(int i=0;i<e;i++)
       {
              char ch1,ch2;
              cin>>ch1>>ch2;
              adj[ch1].PB(ch2);
              adj[ch2].PB(ch1);
       }
       char source='b',dest='a';
       //BFS(source,dest);
       for(auto x:adj)
       {
              cout<<x.fi<<"--> ";
              for(auto y:x.se)
              {
                     cout<<y<<" ";
              }
              cout<<endl;
              vis[x.fi]=false;
       }
       DFS(source);
       return 0;
}