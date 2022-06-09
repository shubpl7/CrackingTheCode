#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0]=dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-4];
    cout<<dp[n];
    return 0;
}