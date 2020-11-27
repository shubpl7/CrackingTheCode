#include<bits/stdc++.h>
//*************** Constraints are always Imaginary,I'm real **************
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
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
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,m;
       cin>>n>>m;
       vector<int> sweets(n+1);
       for(int i=1;i<=n;i++)
       {
              cin>>sweets[i];
       }
       sort(sweets.begin()+1,sweets.end());
       int PrefixSum[n+1]={0};
       PrefixSum[1]=sweets[1];
       for(int i=2;i<=n;i++)
       {
              PrefixSum[i]=PrefixSum[i-1]+sweets[i];
       }
       int ans[n+1]={0};
       for(int i=1;i<=n;i++)
       {
              if(i>m)
                     ans[i]=ans[i-m]+PrefixSum[i];
              else
                     ans[i]=PrefixSum[i];
              cout<<ans[i]<<" ";
       }
       return 0;
}