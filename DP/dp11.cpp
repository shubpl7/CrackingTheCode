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
       int m,n,p;
       cin>>m>>n>>p;
       VVI cell(m+1,VI(n+1,1));
       while(p--)
       {
              int u,v;
              cin>>u>>v;
              cell[u][v]=0;
       }
       VVI dp(m+1,VI(n+1,0));
       if(cell[1][1])
              dp[1][1]=1;
       for(int j=2;j<=n;j++)
              if(cell[1][j])
                     dp[1][j]+=dp[1][j-1];
       for(int j=2;j<=m;j++)
              if(cell[j][1])
                     dp[j][1]+=dp[j-1][1];
       for(int i=2;i<=m;i++)
       {
              for(int j=2;j<=n;j++)
              {
                     if(cell[i][j])
                            dp[i][j]+=((dp[i-1][j]+dp[i][j-1])%MOD);
              }
       }
       // for(int i=1;i<=m;i++)
       // {
       //        for(int j=1;j<=n;j++)
       //               cout<<dp[i][j]<<" ";
       //        cout<<endl;
       // }
       cout<<dp[m][n];
       return 0;
}