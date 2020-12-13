//counting stars
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
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int n,m;
       cin>>n>>m;
       VVI cake(n,VI(n,0));
       for(int i=1;i<=m;i++)
       {
              int x,y;
              cin>>x>>y;
              x--;
              y--;
              cake[x][y]=1;
       }
       int dp[n][n];
       dp[0][0]=cake[0][0];
       for(int j=1;j<n;j++)
       {
              dp[0][j]=dp[0][j-1]+cake[0][j];
              dp[j][0]=dp[j-1][0]+cake[j][0];
       }
       for(int i=1;i<n;i++)
       {
              for(int j=1;j<n;j++)
              {
                     dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+cake[i][j];
              }
       }
       //iterate through cuts.
       int ans=0;
       for(int x=0;x<=n-2;x++)
       {
              for(int y=0;y<=n-2;y++)
              {
                     int first = dp[x][y];
                     int second = dp[n-1][y]-first;
                     int third = dp[x][n-1]-first;
                     int fourth = dp[n-1][n-1]-first-second-third;
                     cout<<min(first,min(second,min(third,fourth)))<<endl;
                     ans=max(ans,min(first,min(second,min(third,fourth))));
              }
       }
       cout<<ans;
       return 0;
}