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
struct box{
       int l,b,h;
};
bool comp(box b1, box b2)
{
       return b1.l*b1.b>b2.l*b2.b;
}
void compute(vector<box> &v)
{
       for(auto x:v)
       {
              cout<<x.l<<" "<<x.b<<" "<<x.h<<endl;
       }
       int n=v.size();
       int dp[n];
       dp[0]=v[0].h;
       for(int i=1;i<n;i++)
       {
              dp[i]=v[i].h;
              for(int j=0;j<i;j++)
              {
                     if(v[j].l>v[i].l && v[j].b>v[i].b)
                            dp[i]=max(dp[i],dp[j]+v[i].h);
              }
       }
       int ans=-1;
       for(int i=0;i<n;i++)
       {
              ans=max(ans,dp[i]);
              cout<<dp[i]<<" ";
       }
       cout<<"\n"<<ans;
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
       vector<box> v;
       for(int i=1;i<=n;i++)
       {
              int length,width,depth;
              cin>>length>>width>>depth;
              box b1;
              b1.h=depth,b1.l=max(length,width),b1.b=min(length,width);
              v.PB(b1);
              b1.h=width,b1.l=max(length,depth),b1.b=min(length,depth);
              v.PB(b1);
              b1.h=length,b1.l=max(depth,width),b1.b=min(depth,width);
              v.PB(b1);
       }
       sort(v.begin(),v.end(),comp);
       compute(v);
       return 0;
}