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
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
              int n;
              cin>>n;
              VI boss(n+1);
              for(int i=1;i<=n;i++)
                     cin>>boss[i];
              
              VVI dp(2,VI(n+1,0));
              dp[0][n]=boss[n];
              dp[0][n-1]=boss[n-1];
              dp[1][n]=0;
              dp[1][n]=0;
              for(int i=n-2;i>=1;i--)
              {
                     dp[1][i]=min(dp[0][i+1],dp[0][i+2]);
                     dp[0][i]=min(boss[i]+dp[1][i+1],boss[i]+boss[i+1]+dp[1][i+2]);
                     
              }
              cout<<dp[0][1]<<endl;
       }
       return 0;
}