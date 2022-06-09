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
    int n = s.length();
    int i=0, j=0;
    set<char> myset;
    while(i<n) {
        cout<<s[i]<<endl;
        myset.insert(s[i]);
        j = i+1;
        while(j<n && (myset.find(s[j])==myset.end())){
            //j is valid
            myset.insert(s[j]);
            cout<<s.substr(i,(j-i+1))<<endl;
            j++;
        }
        i++;
        myset.clear();
    }
    return 0;
}