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
              int n;
              cin>>n;
              VVI mat(n+1,VI(n+1));
              for(int i=1;i<=n;i++)
                     for(int j=1;j<=n;j++)
                            cin>>mat[i][j];
              int ans=0;
              for(int i=1;i<=n;i++)
              {
                     int stx=1,sty=i;
                     int sum=0;
                     while(stx<=n && sty<=n)
                     {
                            sum+=mat[stx][sty];
                            stx++;
                            sty++;
                     }
                     ans=max(ans,sum);
              }
              for(int i=2;i<=n;i++)
              {
                     int stx=i,sty=1;
                     int sum=0;
                     while(stx<=n && sty<=n)
                     {
                            sum+=mat[stx][sty];
                            stx++;
                            sty++;
                     }
                     ans=max(ans,sum);
              }
              cout<<"Case #"<<ti<<": "<<ans<<endl;
       }
       return 0;
}