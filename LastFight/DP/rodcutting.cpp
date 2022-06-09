#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<vector<int> > memo;
int computeMaxProfit(int n, int * len ,int * val, int L) {

    int dp[L+1][n+1];
    for(int i=0;i<=L;i++)
        dp[i][0] = 0;
    for(int i=0;i<=n;i++)
        dp[0][i] = 0;
    for(int i=1;i<=L;i++) {
        for(int j = 1;j<=n;j++) {
            if(len[j-1]>i)
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = max(dp[i][j-1], val[j-1]+dp[i-len[j-1]][j]);
        }
    }
    for(int i=1;i<=L;i++)
    {
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int x = L, y = n;
    while(x>0 && y>0) {
        if(dp[x][y]==dp[x][y-1])
            y--;
        else if(x-len[y-1]>=0 && (dp[x][y]==val[y-1]+dp[x-len[y-1]][y]))
        {
            cout<<"Cut made of length: "<<len[y-1]<<endl;
            x-=len[y-1];
        }
        else
            x--;

    }
    return dp[L][n];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int n, L;
    cin>>L>>n;
    memo.resize(n+1, vector<int>(L+1, -1));
    int len[n], val[n];
    for(int i=0;i<n;i++)
        cin>>len[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<computeMaxProfit(n, len , val, L);
    return 0;
}