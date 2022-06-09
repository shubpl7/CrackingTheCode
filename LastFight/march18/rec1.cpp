#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void fun(int i, string &s){
    if(i==s.length()-1)
        cout<<s<<endl;
    for(int j=i;j<s.length();j++){
        swap(s[i], s[j]);
        fun(i+1, s);
        swap(s[i], s[j]);
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
    string s = "ROD";
    fun(0, s);
    return 0;
}