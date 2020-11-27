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
              int a,b,q;
              cin>>a>>b>>q;
              VI prefix(a*b+1,0);
              for(int i=1;i<=a*b;i++)
              {
                     int x1=(i%a)%b;
                     int x2=(i%b)%a;
                     if(x1!=x2)
                     {
                            prefix[i]=prefix[i-1]+1;
                     }
                     else
                            prefix[i]=prefix[i-1];
              }
              while(q--)
              {
                     int l,r;
                     cin>>l>>r;
                     int g1=(r/(a*b))*prefix[a*b]+prefix[r%(a*b)];//G(r)
                     l--;
                     int g2=(l/(a*b))*prefix[a*b]+prefix[l%(a*b)];//G(l-1)
                     cout<<g1-g2<<" ";
              }
              cout<<endl;
       }
       return 0;

       
}