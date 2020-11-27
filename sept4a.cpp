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
       while(t--)
       {
              int a,b,x,y,n;
              cin>>a>>b>>x>>y>>n;
              int k1=max(a-n,x);
              int k2=max(b-n,y);
              if(k1<k2)
              {
                     n-=(a-k1);
                     cout<<k1*max(b-n,y)<<endl;
              }
              else
              {
                     n-=(b-k2);
                     cout<<k2*max(a-n,x)<<endl;
              }       
              
       }
       return 0;
}