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
VVI mat;
VVI vis;
int r,c;
int SizeOfIsland=0;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool IsSafe(int x,int y)
{
       if(x>=1 && x<=r && y>=1 && y<=c && mat[x][y]==1)
              return true;
       return false;
}
void DFS(int x,int y)
{
       SizeOfIsland++;
       mat[x][y]=2;
       for(int i=0;i<=4;i++)
       {
              int newx=x+dx[i];
              int newy=y+dy[i];
              if(IsSafe(newx,newy))
                     DFS(newx,newy);
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
       int t;
       cin>>t;
       while(t--)
       {
              cin>>r>>c;
              mat.resize(r+1,VI(c+1));
              vis.resize(r+1,VI(c+1,0));
              for(int i=1;i<=r;i++)
              {
                     for(int j=1;j<=c;j++)
                     {
                            cin>>mat[i][j];
                     }
              }
              int NoOfComponents=0,ans=-1;
              for(int i=1;i<=r;i++)
              {
                     for(int j=1;j<=c;j++)
                     {
                            if(mat[i][j]==1)
                            {
                                   SizeOfIsland=0;
                                   DFS(i,j);
                                   NoOfComponents++;
                                   ans=max(ans,SizeOfIsland);
                            }       
                     }
              }
              cout<<NoOfComponents<<endl;
              cout<<ans<<endl;
              for(int i=1;i<=r;i++)
              {
                     for(int j=1;j<=c;j++)
                     {
                            cout<<mat[i][j]<<" ";
                     }
                     cout<<endl;
              }
       }
       return 0;
}