#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
bool isPalindrome(int l, int r, string &s){
    if(l==r)
        return true;
    if(s[l]==s[r])
        return isPalindrome(l+1, r-1, s);
    else
        return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string A="mada";
    cout<<isPalindrome(0, (int)A.length()-1, A);
    return 0;
}