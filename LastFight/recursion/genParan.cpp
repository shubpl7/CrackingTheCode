#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void genParan(int idx, int open, int close, int n, string out) {
    if(idx==2*n){
        cout<<out<<endl;
        return;
    }
    if(open<n) {
        genParan(idx+1, open+1, close, n, (out+"("));
    }
    if(close<open){
        genParan(idx+1, open, close+1, n, (out+")"));
    }
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
    string out = "";
    genParan(0,0,0,n,out);
    return 0;
}