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
int n,m,k;
VVI adj;
VVI vis;
VPII burningTrees;
bool IsSafe(int x, int y)
{
       if(x>=1 && x<=n && y>=1 && y<=m && !vis[x][y])
              return true;
       return false;
}
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
void BFS()
{
       queue<pair<int,int>> q;
       for(int i=0;i<k;i++)
       {
              q.push(burningTrees[i]);
              int x=burningTrees[i].fi;
              int y=burningTrees[i].se;
              vis[x][y]=1;
       }
       PII ans;
       while(!q.empty())
       {
              auto u = q.front();
              //cout<<u.fi<<"   "<<u.se<<endl;
              q.pop();
              ans=u;
              for(int i=0;i<8;i++)
              {
                     int newx=u.fi+dx[i];
                     int newy=u.se+dy[i];
                     if(IsSafe(newx,newy))
                     {
                            vis[newx][newy]=1;
                            q.push({newx,newy});
                     }
              }
       }
       cout<<ans.fi<<" "<<ans.se;
       
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
       adj.resize(n+1,VI(m+1));
       vis.resize(n+1,VI(m+1,false));
       cin>>k;
       burningTrees.resize(k);
       for(int i=0;i<k;i++)
       {
              int x,y;
              cin>>x>>y;
              burningTrees[i]={x,y};
       }
       // for(auto x:burningTrees)
       // {
       //        cout<<x.fi<<" "<<x.se<<endl;
       // }
       BFS();
       return 0;
}