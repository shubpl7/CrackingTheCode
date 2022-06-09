#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
set<string> set1;
void permute(string &s, int idx) {
    if(idx==s.length()){
        cout<<s<<endl;
        return;
    }
    for(int j = idx;j<s.length();j++) {
        if(j!=idx && s[j]==s[idx])
            continue;
        swap(s[idx], s[j]);
        permute(s, idx+1);
        swap(s[idx], s[j]);
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
    string s;
    cin>>s;
    permute(s,0);
    
    return 0;
}