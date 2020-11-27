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
VI w,p;
int KS(int n,int c)
{
       cout<<"KS->"<<n<<" "<<c<<endl;
       if(n==0 || c==0)//base case
              return 0;
       int inc=0;
       int exc=0;
       if(c-w[n]>=0)
       {
              inc=p[n]+KS(n-1,c-w[n]);
       }
       exc=KS(n-1,c);
       return max(inc,exc);
       //return max(c-w[n]>=0?p[n]+KS(n-1,c-w[n]):0,KS(n-1,c));
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,c;
       cin>>n>>c;
       w.resize(n+1);
       p.resize(n+1);
       for(int i=1;i<=n;i++)
              cin>>w[i];
       for(int i=1;i<=n;i++)
              cin>>p[i];
       cout<<KS(n,c);
       return 0;
}