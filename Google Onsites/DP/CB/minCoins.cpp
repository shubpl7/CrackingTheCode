#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int minCoinsTopDown(VI coins, int n, VI & dp) {
    if(n==0)
        return 0;
    if(dp[n]!=INT_MAX)
        return dp[n];
    int ans = INT_MAX;
    for(auto x: coins) {
        if(n-x>=0) {
            ans =  min(ans, 1+minCoinsTopDown(coins, n-x, dp));
        }
    }
    return dp[n]=ans;
}

int minCoinsBottomUp(VI coins, int n) {
    VI dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        for(auto x: coins) {
            if(i-x>=0) {
                dp[i] = min(dp[i], 1+dp[i-x]);
            }
         }
    }
    return dp[n];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    vector<int> coins{1,7,10};
    int n = 15;
    vector<int> dp(n+1, INT_MAX);
    cout<<minCoinsBottomUp(coins, n);
    return 0;
}