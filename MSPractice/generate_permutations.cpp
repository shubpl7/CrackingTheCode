//generate all strings from a given permutation

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void pem(string &str, int s, int e){
    if(s==e){
        cout<<str<<endl;
        return;
    }
    for(int i=s;i<=e;i++) {
        swap(str[i],str[s]);
        pem(str,s+1,e);
        swap(str[i],str[s]);
    }
}
void solve(string str) {
    int n = str.length();
    pem(str,0,n-1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str;
    cin>>str;
    solve(str);
    return 0;
}