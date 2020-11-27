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
struct cell{
       int x,y,time;
       cell(int a,int b,int c)
       {
              x=a;y=b;time=c;
       }
};
VVI mat;
VVI vis;
int r,c;
vector<cell> source;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool IsSafe(int x,int y)
{
       if(x>=1 && x<=r && y>=1 && y<=c && mat[x][y]==1)
              return true;
       return false;
}
int BFS()
{
       queue<cell> q;
       for(auto x:source)
       {
              q.push(x);
              vis[x.x][x.y]=1;
       } 
       int ans=0;
       while(!q.empty())
       {
              
              auto u = q.front();
              ans=u.time;
              q.pop();
              int current_x = u.x;
              int current_y = u.y;
             // cout<<"BFS "<<current_x<<" "<<current_y<<" "<<ans<<endl;
              for(int i=0;i<4;i++)
              {
                     int newx= current_x+dx[i];
                     int newy = current_y+dy[i];
                     if(IsSafe(newx,newy))
                     {
                            //vis[newx][newy]=1;
                            mat[newx][newy]=2;
                            cell c1(newx,newy,u.time+1);
                            q.push(c1);
                     }
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
       int t;
       cin>>t;
       while(t--)
       {
              cin>>r>>c;
              mat.resize(r+1,VI(c+1));
              vis.resize(r+1,VI(c+1,0));
              cell SourceCell(-1,-1,0);
              for(int i=1;i<=r;i++)
              {
                     for(int j=1;j<=c;j++)
                     {
                            cin>>mat[i][j];
                            if(mat[i][j]==2)
                            {
                                   cell c(i,j,0);
                                   source.PB(c);
                            }
                            
                     }
              }
              bool flag=false;
              int g=BFS();
              for(int i=1;i<=r;i++)
              {
                     for(int j=1;j<=c;j++)
                     {
                            if(mat[i][j]==1)
                            {
                                   flag=true;
                                   break;
                            }
                     }
                     if(flag)
                            break;
              }
              
              if(flag)
              {
                     cout<<"-1\n";
              }
              else
                     cout<<g<<endl;
              source.clear();
              for(int i=1;i<=r;i++)
                     for(int j=1;j<=c;j++)
                            vis[i][j]=false;
       }
       return 0;
}