//egg-dropping puzzle
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
void compute(int n,int k)
{
       int dp[n+1][k+1];
       for(int j=0;j<=k;j++)
              dp[0][j]=0;
       for(int j=1;j<=k;j++)
              dp[1][j]=1;
       for(int j=2;j<=n;j++)
       {
              dp[j][1]=j;
       }
       for(int i=2;i<=n;i++)
       {
              
              for(int j=2;j<=k;j++)
              {
                     int ans = INT64_MAX;
                     for(int x=1;x<=i;x++)
                     {
                            ans = min(ans,1+max(dp[x-1][j-1],dp[i-x][j]));
                     }
                     dp[i][j]=ans;
              }
       }

       for(int i=1;i<=n;i++)
       {
              for(int j=1;j<=k;j++)
              {
                     cout<<dp[i][j]<<" ";
              }
              cout<<endl;
       }
       cout<<"\n"<<dp[n][k];
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int n,k;
       cin>>n>>k;
       compute(n,k);
       return 0;
}