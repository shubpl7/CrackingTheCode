// LIS
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
VI v;
void LIS1()
{
       //naive implementation
       int n=v.size()-1;
       int LIS[n+1];
       LIS[1]=1;
       for(int i=2;i<=n;i++)
       {
              LIS[i]=1;
              for(int j=i-1;j>=1;j--)
              {
                     if(v[j]<v[i])
                     {
                            LIS[i]=max(LIS[i],LIS[j]+1);
                     }
              }
       }
       int ans=1;
       for(int i=1;i<=n;i++)
       {
              ans=max(LIS[i],ans);
              cout<<LIS[i]<<" ";
       }
       cout<<"\n"<<ans;
       
}
void LIS2()
{
       //implementation using Binary search
       int n=v.size()-1;
       VI dp(n+1,INT64_MAX);
       dp[0]=INT64_MIN;
       for(int i=1;i<=n;i++)
       {
              int idx = upper_bound(dp.begin(),dp.end(),v[i])-dp.begin();//pos+1
              if(dp[idx-1]<v[i] && v[i]<dp[idx])
                     dp[idx]=v[i];
       }
       int lis=-1;
       for(int i=1;i<=n;i++)
       {
              if(dp[i]!=INT64_MAX)
                     lis=i;
              cout<<dp[i]<<" ";
       }
       cout<<endl<<lis;

}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
       v.resize(n+1);
       for(int i=1;i<=n;i++)
              cin>>v[i];
       LIS2();
       return 0;
}