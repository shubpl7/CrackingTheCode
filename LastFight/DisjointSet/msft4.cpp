#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
bool isUnique(string s) {
    sort(s.begin(), s.end());
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1])
            return false;
    }
    return true;
}
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
    vector<string> arr(n);
    for(auto &x: arr)
        cin>>x;
    int maxL = 0;
    for(int i=1;i<(1<<n);i++) {
        string test="";
        if(__builtin_popcount(i)==1)
            continue;
        for(int j=0;(1<<j)<=i;j++) {
            if(i & (1<<j)) {
                test += arr[j];
            }
        }
        if(isUnique(test)) {
            cout<<test<<endl;
            maxL = max(maxL, (int)test.length());
        }
    }
    cout<<"MaxL: "<<maxL<<endl;
    return 0;
}