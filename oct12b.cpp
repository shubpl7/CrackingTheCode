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
double pi = pi=3.141592653589793238462;

VI pie;
int n,f;
bool IsPossible(double mid)
{
       int count=0;
       if(mid==0)
              return true;
       for(auto x:pie)
       {
              int y = ((pi*x*x)/(mid));
              count+=y;
              if(count>=(f+1))
                     return true;
       }
       return false;
}
double BSearch()
{
       int maxRadii = *max_element(pie.begin(),pie.end());
       double e = pi*maxRadii*maxRadii;
       double s=0;
       double ans=-1;
       while(s<=e)
       {
              double mid = s+(e-s)/(2.0);
              if(IsPossible(mid))
              {
                     ans=mid;
                     s=mid+1e-6;
              }
              else
                     e=mid-1e-6;
       }
       return ans;
}
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
              cin>>n>>f;
              pie.resize(n);
              for(auto &x:pie)
                     cin>>x;
              double ans = BSearch();
              cout<<fixed<<setprecision(4)<<ans<<endl;
              pie.clear();
       }
       return 0;
}