#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
VI w,p;
struct Node{
       int row,col;
       int val;
       bool isPresent;
};
vector<vector<Node>> dp;
int KS(int n,int c)
{
       cout<<"KS-> "<<n<<" "<<c<<endl;
       if(n==0 ||c==0)
              return 0;
       return max(c-w[n]>=0?p[n]+KS(n-1,c-w[n]):0,KS(n-1,c));
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,c;
       cin>>n>>c;
       w.resize(n+1);p.resize(n+1);
       dp.resize(n+1,vector<Node>(c+1));
       for(int i=1;i<=n;i++)
              cin>>w[i];
       for(int i=1;i<=n;i++)
              cin>>p[i];
       //cout<<KS(n,c);
       for(int i=0;i<=c;i++)
       {
              dp[0][i].val=0;
              dp[0][i].isPresent=false;
              dp[0][i].row=0;
              dp[0][i].col=i;
       }
       for(int i=0;i<=n;i++)
       {
              dp[i][0].val=0;
              dp[i][0].isPresent=false;
              dp[i][0].col=0;
              dp[i][0].row=i;
       }
       for(int i=1;i<=n;i++)
       {
              for(int j=0;j<=c;j++)
              {
                     int inc=0;
                     if(j-w[i]>=0)
                            inc=p[i]+dp[i-1][j-w[i]].val;
                     int exc=dp[i-1][j].val;
                     if(exc>inc)
                     {
                            dp[i][j].val=exc;
                            dp[i][j].isPresent=false;
                            dp[i][j].row=i-1;
                            dp[i][j].col=j;
                     }
                     else
                     {
                            dp[i][j].val=inc;
                            dp[i][j].isPresent=true;
                            dp[i][j].row=i-1;
                            dp[i][j].col=j-w[i];
                     }
                     
              }
       }
       cout<<"ans is : "<<dp[n][c].val<<endl;
       int row=n,col=c;
       for(int i=0;i<=n;i++)
       {
              for(int j=0;j<=c;j++)
              {
                     cout<<dp[i][j].row<<" "<<dp[i][j].col<<" "<<dp[i][j].val<<" "<<dp[i][j].isPresent<<"     ";
              }
              cout<<endl;
       }
       while(row>0)
       {
              if(dp[row][col].isPresent)
                     cout<<row<<" ";
              row=dp[row][col].row;
              col=dp[row][col].col;
       }
       return 0;
}