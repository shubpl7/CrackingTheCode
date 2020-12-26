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
VI prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<vector<int>> pfs(51);
VI arr;
int n;
int dp[50][1<<15];
int KNS(int idx,int mask)
{
       //cout<<"KNS-->"<<idx<<" "<<mask<<endl;
       if(idx<0)
              return 0;
       if(dp[idx][mask]!=-1)
              return dp[idx][mask];
       //edge-case
       if(arr[idx]==1)
       {
              int ans = 1+KNS(idx-1,mask);
              dp[idx][mask]=ans;
              return ans;
       }
       int opt1=KNS(idx-1,mask);
       int newmask = mask;
       for(auto x:pfs[arr[idx]])
       {
              if(newmask & (1<<x))
              {
                     return dp[idx][mask]=opt1;
              }
              newmask|=(1<<x);
       }
       int opt2 = 1+KNS(idx-1,newmask);
       int ans = max(opt1,opt2);
       dp[idx][mask]=ans;
       return ans;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       for(int i=1;i<=50;i++)
       {
              for(int j=0;j<15;j++)
              {
                     if(i%prime[j]==0)
                            pfs[i].PB(j);
              }
       }
       while(t--)
       {
              cin>>n;
              arr.resize(n);
              for(auto &x:arr)
                     cin>>x;
              memset(dp,-1,sizeof(dp));
              cout<<KNS(n-1,0)<<endl;
              arr.clear();
       }
       return 0;
}