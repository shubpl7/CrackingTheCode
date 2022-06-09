#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int findScore(int N, vector<int> AR, int Q, vector<vector<int> > ORDERS) {
    
    vector<int> Count(N+2,0), PreCount(N+2,0), LastEx(N+2,0), PreLastEx(N+2,0);
    for(auto order: ORDERS) {
        int l = order[0], r = order[1], x = order[2];
        Count[l]++;
        Count[r+1]--;
        LastEx[l] = x; 
    }
    for(int i=1;i<=N;i++) {
        PreCount[i] = PreCount[i-1] + Count[i];
        if(LastEx[i])
            PreLastEx[i] = LastEx[i];
        else
            PreLastEx[i] = PreLastEx[i-1];
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(PreCount[i]==0){
            ans ^= AR[i-1];
        }
        else{
            if(PreCount[i]%2!=1){
                ans ^= PreLastEx[i];
            }
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int N,Q;
    vector<int> AR(N);
    for(auto &x: AR)
        cin>>x;
    cin>>Q;
    vector<vector<int>> ORDERS(Q, vector<int>(3));
    for(int i=0;i<Q;i++){
        int a, b, c;
        cin>>a>>b>>c;
        ORDERS[i][0] = a;ORDERS[i][1] = b;ORDERS[i][2] = c;
    }
    cout<<findScore(N, AR, Q, ORDERS);
    return 0;
}