#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int lcs(int x, int y, string s1, string s2)
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
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(), B.end());
        return lcs(A.length(), A.length(), A, B);
    }

int longestPalinSubseqBottomUp(string A) {
        //code here
        int n = A.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int k = 2;k<= n;k++) {
            //size k
            for(int i=0;i<n-k+1;i++) {
                int j = i+k-1;
                if(A[i]==A[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }
                else
                    dp[i][j] = max( dp[i][j-1], dp[i+1][j]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][n-1];
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