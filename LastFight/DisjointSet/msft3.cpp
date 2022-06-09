#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int stringToNo(string s) {
    int ans=0;
    for(auto x: s) {
        ans = ans*2 + x-'0';
        cout<<"curr :"<<ans<<" ";
    }
    cout<<endl;
    return ans;
}
int fun(int n) {
    if(n==0)
        return 1;
    int temp = 1;
    int currCnt = 0, ans = 0;
    while (n)
    {
        if(!(temp & n)) {
            currCnt++;
        }
        else
            currCnt = 0;
        ans = max(ans, currCnt);
        n >>= 1LL;
        /* code */
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
    string s;
    cin>>s;

    cout<<fun(stringToNo(s));
    return 0;
}