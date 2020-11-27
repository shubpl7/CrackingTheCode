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
       int n,l,r,x;
       cin>>n>>l>>r>>x;
       VI diff(n);
       for(auto &x:diff)
              cin>>x;
       int lim=1<<n;
       int count=0;
       for(int i=1;i<lim;i++)
       {
              set<int> prblmset;
              int sum=0;
              for(int j=0;j<n;j++)
              {
                     if(i & (1<<j))
                     {
                            prblmset.insert(diff[n-j-1]);
                            sum+=diff[n-j-1];
                     }
              }
              if((*prblmset.rbegin()-*prblmset.begin())>=x && sum>=l && sum<=r)
                     count++;
       }
       cout<<count;
       return 0;
}