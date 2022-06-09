#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<vector<string> > memo;
string s1,s2;
int m, n;
// string LCSTopDown(int i, int j) {
//     if(i<0 || j<0) {
//         return "";
//     }
//     if(memo[i][j]!="-1")
//         return memo[i][j];
//     if(s1[i]==s2[j]){
//         return LCS(i-1,j-1)+s1[i];
//     }
//     string left = LCS(i-1, j);
//     string right = LCS(i, j-1);
//     return left.length()>right.length()?left:right;
// }


int lcsSpaceOptimized(int x, int y, string s1, string s2)
    {
        // your code here
        // int dp[2][y+1];
        // for(int j=0;j<=y;j++)
        //     dp[0][j] = 0;
        vector<int> prev(y+1,0), curr(y+1,0);
        for(int i=1;i<=x;i++) {
            for(int j=1;j<=y;j++) {
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[y];
    }


int LCSBottomUp() {
    int dp[2][m];
    int prev=0;int curr = 1;
    for(int j=0, flag=0;j<m;j++){
        if(s1[j]==s2[0]){
            dp[prev][j]=1;
            flag=1;
        }
        else{
            if(flag)
                dp[prev][j]=1;
            else
                dp[prev][j]=0;
        }
        cout<<dp[prev][j]<<" ";
    }
    cout<<endl;

    
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(j==0) {
                if(s1[j]==s2[i])
                    dp[curr][j] = 1;
                else
                    dp[curr][j] = 0;
            }
            else{
                if(s1[j]==s2[i]){
                    dp[curr][j] = dp[prev][j-1] +1;
                }
                else
                    dp[curr][j] = max( dp[prev][j], dp[curr][j-1]);
            }
            cout<<dp[curr][j]<<" ";
        }
        cout<<endl;
        curr ^= 1;
        prev ^=1;
    }
    return dp[prev][m-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    cin>>s1>>s2;
    m = s1.length();
    n = s2.length();
    memo.resize(m, vector<string>(n,"-1"));
    cout<<LCSBottomUp();
    return 0;
}