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
              VI v1(a*b+1);
              VI v2(a*b+1);
              VI prefix(a*b+1,0);
              for(int i=1;i<=a*b;i++)
              {
                     v1[i]=(i%a)%b;
                     v2[i]=(i%b)%a;
                     if(v1[i]==v2[i])
                            prefix[i]=prefix[i-1];
                     else
                     {
                            prefix[i]=prefix[i-1]+1;
                     }
                     
              }
              while(q--)
              {

                     int l,r;
                     cin>>l>>r;
                     int x1=(r/(a*b))*prefix[a*b]+prefix[r%(a*b)];
                     int l1=l-1;
                     int x2=(l1/(a*b))*prefix[a*b]+prefix[l1%(a*b)];
                     cout<<x1-x2<<" ";
              }
              cout<<endl;
       }
       return 0;
}