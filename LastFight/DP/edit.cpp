#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<vector<int>> memo;
  int ed(string s, string t, int m, int n) {
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(memo[m][n]!=-1) {
        return memo[m][n];
    }
    if(s[m-1]==t[n-1]){
        return memo[m][n] = ed(s, t, m-1, n-1);
    }
    return memo[m][n] = 1+min(ed(s, t, m-1, n-1), min(ed(s, t, m, n-1),ed(s, t, m-1, n)));
    
  }
    int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        memo.resize(m+1, vector<int> (n+1, -1));
        return ed(s,t,m,n);
    }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    return 0;
}