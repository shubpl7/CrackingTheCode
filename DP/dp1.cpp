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
int memo[10000];
int minCoins(int *coins,int n, int sum)
{
       cout<<"mincoins--"<<sum<<endl;
       if(memo[sum]!=-1)
              return memo[sum];
       if(sum<=0)
       {
              memo[0]=0;
              return 0;
       }
       int minVal=INT64_MAX;
       for(int i=0;i<n;i++)
       {
              if(sum-coins[i]>=0)
                     minVal=min(minVal,minCoins(coins,n,sum-coins[i]));
       }
       memo[sum]=minVal+1;
       return minVal+1;
}
int mincoinsBottomTop(int *coins,int n,int sum)
{
       int dp[sum+1]={0};
       int parent[sum+1];
       parent[0]=-1;
       dp[0]=0;
       for(int i=1;i<=sum;i++)
       {
              dp[i]=INT64_MAX;
              for(int k=0;k<n;k++)
              {
                     if(i-coins[k]>=0)
                     {
                            if(dp[i-coins[k]]+1<dp[i])
                            {
                                   dp[i]=dp[i-coins[k]]+1;
                                   parent[i]=i-coins[k];
                            }
                     }
              }
       }
       int par=sum;
       while(par!=-1)
       {
              cout<<par<<"--->";
              par=parent[par];
       }
       cout<<endl;
       return dp[sum];
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int coins[]={1,3,5};
       int n=sizeof(coins)/sizeof(coins[0]);
       int sum=8;
       memset(memo,-1,sizeof(memo));
       //cout<<minCoins(coins,n,sum);
       cout<<mincoinsBottomTop(coins,n,sum);
       return 0;
}