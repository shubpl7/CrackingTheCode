#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int beautifulSubsequences(int K, vector<int> A) {
    int n = A.size();
    unordered_map<int, vector<int>> mp;
    vector<int> dp(n,0);
    int count = 1;
    for(int j=n-1;j>=0;j--) {
        int temp = A[j]%K;
        mp[temp].push_back(j);
        int conjugate = (K-temp)%K;
        dp[j] = 1;
        if(mp.count(conjugate)!=0){
            for(auto x: mp[conjugate]) {
                dp[j] += dp[x];
            }
        }
        count += dp[j];
    }
    return count;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int N,K;
    cin>>N>>K;
    vector<int>  A(N);
    for(auto &x: A)
        cin>>x;
    int res = beautifulSubsequences(K, A);
    cout<<res;
    return 0;
}