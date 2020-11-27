#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
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
VI height;
VVI dp;
VI coor;
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
              int n;
              cin>>n;
              height.resize(n+2);
              dp.resize(n+2,VI(3,0));
              coor.resize(n+2);
              for(int i=1;i<=n;i++)
              {
                     cin>>coor[i]>>height[i];
              }
              height[0]=0;height[n+1]=0;
              coor[0]=INT64_MIN;coor[n+1]=INT64_MAX;
              dp[1][0]=0;dp[1][1]=1;
              if(coor[2]-coor[1]>height[1])
                     dp[1][2]=1;
              for(int i=2;i<=n;i++)
              {
                     dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
                     //finding dp[i][1]
                     if(coor[i]-coor[i-1]>height[i]+height[i-1])
                            dp[i][1]=dp[i-1][2]+1LL;
                     if(coor[i]-coor[i-1]>height[i])
                            dp[i][1]=max(dp[i][1],max(dp[i-1][1],dp[i-1][0])+1LL);
                     else
                     {
                            dp[i][1]=dp[i][0];
                     }
                     
                     //finding dp[i][2]
                     if(coor[i+1]-coor[i]>height[i])
                     {
                            dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+1LL;

                     }
                     else
                            dp[i][2]=max(dp[i][2],dp[i][0]);
                     
                     
              }
              // for(auto x:dp)
              // {
              //        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
              // }
              cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
              
       return 0;
}