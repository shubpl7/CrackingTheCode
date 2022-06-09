#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int fruitBasketsUtil(int A, int B, vector<vector<int> > &dp) {
    if((A==1 && B==2) || (A==2 && B==1)) {
        return dp[A][B]=1;
    }
    else if(A<1 || B<1)
        return 0;
    if(dp[A][B]!=-1)
        return dp[A][B];
    if((A>=1 && B>2) || (A>2 && B>=1))
        return dp[A][B] = 1+ max(fruitBasketsUtil(A-1,B-2,dp), fruitBasketsUtil(A-2,B-1,dp));
    return 0;
}
int fruitBaskets(int A, int B) {
    vector<vector<int> > dp(A+1, vector<int>(B+1,-1));
    return fruitBasketsUtil(A, B, dp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int A,B;
    cin>>A>>B;
    cout<<fruitBaskets(A, B);
    return 0;
}