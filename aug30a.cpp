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
void solve(VI &v)
{
       int sum=0;
       map<int,VI> mp;
       mp[0].PB(-1);
       for(int i=0;i<v.size();i++)
       {
              sum=sum+v[i];
              sum%=(int)v.size();
              mp[sum].PB(i);
       }
       for(auto x:mp)
       {
              // cout<<x.fi<<" ";
              // for(auto y:x.se)
              //        cout<<y<<"->";
              // cout<<endl;
              if(x.se.size()>=2)
              {
                     int l=x.se[0]+1;
                     int r=x.se[1];
                     cout<<r-l+1<<endl;
                     for(int j=l;j<=r;j++)
                            cout<<j+1<<" ";
                     break;
              }
       }
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
              int n;
              cin>>n;
              VI v(n);
              for(auto &x:v)
                     cin>>x;
              solve(v);
              cout<<endl;
       }
       return 0;
}