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
int n,m;
VI coins;
// ways to make coin change
pair<vector<vector<int>>, bool> coinChangeTopDown(int n, int m, unordered_map<pair<int, int>, vector<vector<int>>> & dp) {
    if(n==0) {
        return {{}, true};
    }
    if(n<0)
        return {{}, false};
    if(n && m<=0) {
        return {{}, false};
    }
    if(dp.count({n,m})) {
        return {dp[{n,m}],dp[{n,m}].size()>0?true:false};
    }
    vector<vector<int>> ans;
    auto temp = coinChangeTopDown(n,m-1, dp);
    if(temp.second){
        ans = temp.first;
    }
    auto temp2 = coinChangeTopDown(n-coins[m-1], m, dp);
    if(temp2.second) {
        for(auto &x: temp2.first) {
            x.push_back(coins[m-1]);
        }
        for(auto &x: temp2.first) {
            ans.push_back(x);
        }
    }
    dp[{n,m}] = ans;
    return {ans, temp.second||temp2.second};

}
void compute()
{
          //here ordering matters
          unordered_map<pair<int, int>, vector<vector<int>>> dp;
          auto ans = coinChangeTopDown(n, m, dp);
          for(auto x: ans.first) {
              for(auto y: x)
                cout<<y<<" ";
            cout<<endl;
          }
}
void compute2()
{
          VVI dp(n+1,VI(m+1,0));
          for(int i=0;i<=m;i++)
                    dp[0][i]=1;
          for(int i=1;i<=n;i++)
          {
                    for(int j=1;j<=m;j++)
                    {
                              dp[i][j]=dp[i][j-1];
                              if(i-coins[j-1]>=0)
                                        dp[i][j]+=(dp[i-coins[j-1]][j]);
                    }
          }
          cout<<dp[n][m];
}
int32_t main()
{
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
         
          
          cin>>n>>m;
          coins.resize(m);
          for(auto &i:coins)
                    cin>>i;
          compute();
          return 0;
}