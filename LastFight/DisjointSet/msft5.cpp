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
    string s;
    cin>>s;
    int i=0,j=0, n = s.length(), ans=0;
    vector<bool> cnt(26, false);
    while(i<n) {
        if(j<n && cnt[s[j]-'a']==false) {
            //we can include all substrings starting from i and ending with j inclusive
            cnt[s[j]-'a'] = true;
            ans += (j-i+1);
            j++;
            
        }
        else{
            // j==n or repeating charater is found
            cnt[s[i]-'a'] = false;
            i++;
        }
    }
    cout<<ans;
    return 0;
}