//https://www.spoj.com/problems/TRT/
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
int n;
//VVI memo;
VI arr;
// int f(int i,int j)
// {
//        //cout<<"f--"<<i<<" "<<j<<endl;
//        if(i>j)
//               return 0;
//        if(memo[i][j]!=-1)
//               return memo[i][j];
//        int df = n-(j-i);
//        int profit = max(arr[i]*df+f(i+1,j),arr[j]*df+f(i,j-1));
//        memo[i][j]=profit;
//        return profit;
// }
int bottomup()
{
       int dp[n+1][n+1];
       memset(dp,-1,sizeof(dp));
       for(int k=0;k<=n-1;k++)
       {
              int i=1;
              for(int j=i+k;j<=n;i++,j++)
              {
                     int df=n-(j-i);
                     if(i==j)
                     {
                            dp[i][j]=max(arr[i]*df,arr[j]*df);
                     }
                     else
                     {
                            dp[i][j]=max(arr[i]*df+dp[i+1][j],arr[j]*df+dp[i][j-1]);
                     }
                     
              }
       }
       // for(int i=1;i<=n;i++)
       // {
       //        for(int j=1;j<=n;j++)
       //               cout<<dp[i][j]<<" ";
       //        cout<<endl;
       // }
       return dp[1][n];
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       cin>>n;
       arr.resize(n+1);
       //memo.resize(n+1,VI(n+1,-1));
       for(int i=1;i<=n;i++)
       {
              cin>>arr[i];
       }
       cout<<bottomup()<<endl;
       return 0;
}