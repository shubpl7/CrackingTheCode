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
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       int ti=0;
       while(t--)
       {
              ti++;
              int w,n;
              cin>>w>>n;
              VI W(w);
              for(auto &x:W)
                     cin>>x;
              int ans=INT64_MAX;
              for(auto y:W)
              {
                     int sum=0;
                     for(auto x:W)
                     {
                            sum+=min(abs(y-x),n-abs(y-x));
                     }
                     ans=min(ans,sum);
              }
              cout<<"Case #"<<ti<<": "<<ans<<endl;
       }
       return 0;
}